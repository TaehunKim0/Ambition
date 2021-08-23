#include "stdafx.h"
#include "SInDoor.h"
#include"SMain.h"
#include"SOutDoor.h"

SInDoor::SInDoor()
{
	OMgr->Release();
	Stop = false;
	In = Sprite::Create("Resource/In.png");

	FMgr = new FightMgr();
	frame = 0;
	BackGround = Sprite::Create("Resource/InDoorBack.png");
	OMgr->Add(BackGround);

	Button1p = Sprite::Create("Resource/InDoor/1p.png");
	Button2p = Sprite::Create("Resource/InDoor/2p.png");

	Button1p->SetPos(400, 300);
	Button2p->SetPos(1000, 300);

	OMgr->Add(Button1p);
	OMgr->Add(Button2p);
	In->SetPos(1920 / 2 - 100, 300);
	Mode = 3;

	Round1End = false;
	Round2End = false;
	Round3End = false;
}

SInDoor::~SInDoor()
{
}

bool SInDoor::SelectMode()
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

			SelectChar = new CharSelect(Mode);
			OMgr->Add(SelectChar);
			Count++;
		}

		ModeSelected = 1;
		return true;
	}

	return false;
}

bool SInDoor::SelectCharacter()
{
	if (SelectChar->SelectEnd)
	{
		switch (Mode)
		{
		case 1:
			FMgr->CreateCharacter(SelectChar->Player1, SelectChar->AI , 1);
			FMgr->Player2->GetEnemy(FMgr->Player1);
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

void SInDoor::Update(float deltaTime)
{
	if (IInput->GetKey(VK_ESCAPE) == KeyState::UP)
	{
		Stop = true;

		if (Stop)
		{
			Stop *= -1;
		}
		return;
	}

	if (Stop)
		return;

	if(!ModeSelected)
		if (!SelectMode())
			return;

	if(!CharacterSelected)
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

	/*if (Round1End == false)
		if (!FMgr->Round())
			return;
		else
		{
			Round1End = true;
			FMgr->EndRound();
		}

	if (Round2End == false)
		if (!FMgr->Round())
			return;
		else
		{
			Round2End = true;
			FMgr->EndRound();
		}

	if (Round3End == false)
		if (!FMgr->Round())
			return;
		else
		{
			Round3End = true;
			FMgr->EndRound();
		}*/

	if (FMgr->Player1WinCount ==3 || FMgr->Player2WinCount == 3)
	{
		frame++;

		if (FMgr->Player1WinCount == 3)
		{
			FMgr->Player1Win->m_Active = true;
		}
		if (FMgr->Player2WinCount == 3)
		{
			FMgr->Player2Win->m_Active = true;
		}

		if(frame >= 360)
			GamDok::Get()->Change(new SOutDoor());

	}
}

void SInDoor::Render()
{
}
