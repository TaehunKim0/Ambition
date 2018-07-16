#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_Punch = new Animation();
	m_Punch->Init(0, 10);
	m_Punch->AddContinueFrame(L"Resource/Example/", 1, 2);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	m_Punch->Update(deltaTime);
}

void Player::Render()
{
	GameObject::Render();

	m_Punch->Render();
}
