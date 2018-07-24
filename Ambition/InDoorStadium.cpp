#include "stdafx.h"
#include "InDoorStadium.h"
#include"Kyo.h"

InDoorStadium::InDoorStadium()
{
	player = new Player();
	player->SetPosition(500, 500);
	player->SetScale(3.f, 3.f);

	BackGround = Sprite::Create(L"Resource/Stage1.png");

	Life = Sprite::Create(L"Resource/Life.png");
	
	ObjectManager::GetInst()->AddObject(BackGround);
	ObjectManager::GetInst()->AddObject(Life);
	//ObjectManager::GetInst()->AddObject(player);
}

InDoorStadium::~InDoorStadium()
{
}

void InDoorStadium::Init()
{
	if (PlayerType == CharacterType::KYO)
	{
		p = new Kyo();
		ObjectManager::GetInst()->AddObject(p);
		p->SetPosition(500, 500);
		p->SetScale(3.f, 3.f);
	}
}

void InDoorStadium::Update(float deltaTime)
{
	//if (player->m_vPosition.y > 500.f)
	//	player->m_vPosition.y = 500.f;
}

void InDoorStadium::Render()
{
}
