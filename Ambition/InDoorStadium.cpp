#include "stdafx.h"
#include "InDoorStadium.h"


InDoorStadium::InDoorStadium()
{
	player = new Player();
	player->SetPosition(500, 500);
	player->SetScale(3.f, 3.f);

	BackGround = Sprite::Create(L"Resource/Stage1.png");
}

InDoorStadium::~InDoorStadium()
{
}

void InDoorStadium::Update(float deltaTime)
{
	player->Update(deltaTime);
}

void InDoorStadium::Render()
{
	
	BackGround->Render();
	player->Render();
}
