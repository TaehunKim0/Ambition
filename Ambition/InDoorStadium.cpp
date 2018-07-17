#include "stdafx.h"
#include "InDoorStadium.h"


InDoorStadium::InDoorStadium()
{
	player = new Player();
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
	player->Render();
}
