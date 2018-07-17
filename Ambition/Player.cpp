#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_APunch = new Animation();
	m_APunch->Init(0, 10);
	m_APunch->SetAnimEndWithFrame(1);
	m_APunch->AddContinueFrame(L"Resource/Example/Punch", 1, 2);

	m_AStand = new Animation();
	m_AStand->Init(0, 10);
	m_AStand->SetAnimEndWithFrame(1);
	m_AStand->AddContinueFrame(L"Resource/Example/Stand", 1, 2);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	FightObject::Update(deltaTime);
}

void Player::Render()
{
	FightObject::Render();
}

void Player::Punch()
{
	if (m_State == State::STAND)
	{
		if (InputSystem->GetKey('H') == KeyState::UP)
		{
			m_State = State::PUNCH;
		}
	}
}

void Player::Kick()
{
}

void Player::Sit()
{
}

void Player::Block()
{
}

void Player::Jump()
{
}

void Player::Move()
{
	if (InputSystem->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		
	}
	if (InputSystem->GetKey(VK_LEFT) == KeyState::PRESS)
	{

	}

	if (InputSystem->GetKey(VK_UP) == KeyState::PRESS)
	{

	}
	if (InputSystem->GetKey(VK_DOWN) == KeyState::PRESS)
	{

	}


}
