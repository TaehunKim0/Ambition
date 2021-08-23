#include "stdafx.h"
#include "STutorial.h"
#include"Characters.h"
#include"SMain.h"

STutorial::STutorial()
{
	OMgr->Release();

	Wall = Sprite::Create("Resource/InDoorBack.png");
	OMgr->Add(Wall);

	FMgr = new FightMgr();
	SelectChar = new CharSelect(1);
	OMgr->Add(SelectChar);
	ObjectMgr::Get()->m_Objects;
	printf("CCCC\n");
}

STutorial::~STutorial()
{
}

void STutorial::SelectCharacter()
{
	if (!SelectChar->SelectEnd)
	{
		printf("AAAA\n");
	}
	else
	{
		SelectChar->SelectEnd = true;
		printf("BBBB\n");
		FMgr->CreateCharacter(SelectChar->Player1, SelectChar->AI, 1);
		CharacterSelected = 1;
		ObjectMgr::Get()->m_Objects;
		FMgr->Player2->GetEnemy(FMgr->Player1);
	}
}

void STutorial::Update(float deltaTime)
{
	if (!CharacterSelected)
	{
		SelectCharacter();
		
	}

	if (CharacterSelected)
	{
		FMgr->Round();

		FMgr->Player1->m_Health = 100;
		FMgr->Player2->m_Health = 100;

		if (IInput->GetKey(VK_ESCAPE) == KeyState::DOWN)
			GamDok::Get()->Change(new SMain());
	}
}

void STutorial::Render()
{
}
