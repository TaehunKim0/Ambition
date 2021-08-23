#include "stdafx.h"
#include "SOutDoor.h"
#include"SMain.h"

SOutDoor::SOutDoor()
{
	OMgr->Release();
	frame = 0;
	FMgr = new FightMgr();

	GameOver = Sprite::Create("Resource/GameOver.png");

	Out = Sprite::Create("Resource/Out.png");

	BackGround = Sprite::Create("Resource/InDoorBack.png");
	OMgr->Add(BackGround);

	Button1p = Sprite::Create("Resource/InDoor/1p.png");
	Button2p = Sprite::Create("Resource/InDoor/2p.png");

	Button1p->SetPos(400, 300);
	Button2p->SetPos(1000, 300);

	OMgr->Add(Button1p);
	OMgr->Add(Button2p);

	OMgr->Add(GameOver);
	GameOver->m_Active = false;
	Out->SetPos(1920 / 2 - 100, 300);

	Mode = 3;

}


SOutDoor::~SOutDoor()
{
}

bool SOutDoor::SelectCharacter()
{
	if (SelectChar->SelectEnd)
	{
		switch (Mode)
		{
		case 1:
			FMgr->CreateCharacter(SelectChar->Player1, SelectChar->AI, 1);
			break;

		case 2:
			FMgr->CreateCharacter(SelectChar->Player1, SelectChar->Player2, 0);
			break;
		}

		CharacterSelected = 1;
		return true;
	}

	return false;
}

bool SOutDoor::SelectMode()
{
	if (CollisionMgr::Get()->BoxMouseTest(Button1p->m_Collision))
	{
		if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			Mode = 1;
		}
	}
	else if (CollisionMgr::Get()->BoxMouseTest(Button2p->m_Collision))
	{
		if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			Mode = 2;
		}
	}

	if (Mode != 3)
	{
		if (Count == 0)
		{
			OMgr->Remove(Button1p);
			OMgr->Remove(Button2p);
			OMgr->Remove(Out);

			SelectChar = new CharSelect(Mode);
			OMgr->Add(SelectChar);
			Count++;
		}
		ModeSelected = 1;
		return true;
	}

	return false;
}

void SOutDoor::Update(float deltaTime)
{
	if (!ModeSelected)
		if (!SelectMode())
			return;

	if (!CharacterSelected)
		if (!SelectCharacter())
			return;

	if (!(FMgr->Player1WinCount == 3 || FMgr->Player2WinCount == 3))
	{
		if (!FMgr->Round())
			return;
		else
		{
			FMgr->EndRound();
		}
	}

	if ((FMgr->Player1WinCount == 3 || FMgr->Player2WinCount == 3))
	{
		frame++;
		GameOver->m_Active = true;

		if (frame >= 280)
		{
			GamDok::Get()->Change(new SMain());
		}
	}
}

void SOutDoor::Render()
{
}
