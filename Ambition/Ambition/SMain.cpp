#include "stdafx.h"
#include "SMain.h"
#include"STutorial.h"
#include"SInDoor.h"
SMain::SMain()
{
	OMgr->Release();
	BackGround = Sprite::Create("Resource/Main.png");

	Tutorial = Sprite::Create("Resource/UI/TUTORIAL.png");
	GameStart = Sprite::Create("Resource/UI/GAME START.png");
	GameEnd = Sprite::Create("Resource/UI/QUIT.png");

	Tutorial->SetPos(54, 646);
	GameStart->SetPos(54, 481);
	GameEnd->SetPos(54, 816);

	OMgr->Add(BackGround);
	OMgr->Add(Tutorial);
	OMgr->Add(GameStart);
	OMgr->Add(GameEnd);
}

SMain::~SMain()
{
}

void SMain::Update(float deltaTime)
{
	//Tutorial->SetPos(MX, MY);
	//printf("MX : %f MY : %f\n",MX,MY);

	if (CollisionMgr::Get()->BoxMouseTest(Tutorial->m_Collision))
	{
		if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			GamDok::Get()->Change(new STutorial());
			return;
		}
	}

	if (CollisionMgr::Get()->BoxMouseTest(GameStart->m_Collision))
	{
		if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			GamDok::Get()->Change(new SInDoor());
			return;
		}
	}

	if (CollisionMgr::Get()->BoxMouseTest(GameEnd->m_Collision))
	{
		if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			exit(0);
		}
	}
	
}

void SMain::Render()
{
}
