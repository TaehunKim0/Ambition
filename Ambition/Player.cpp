#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_APunch = new Animation();
	m_APunch->Init(1, 4, this);
	m_APunch->SetAnimEndWithFrame(1);
	m_APunch->AddContinueFrame(L"Resource/Kyo/Punch/", 1, 6);

	m_AKick = new Animation();
	m_AKick->Init(1, 4, this);
	m_AKick->SetAnimEndWithFrame(1);
	m_AKick->AddContinueFrame(L"Resource/Kyo/Kick/", 1, 6);

	m_AStand = new Animation();
	m_AStand->Init(1, 10, this);
	m_AStand->SetAnimEndWithFrame(0);
	m_AStand->AddContinueFrame(L"Resource/Kyo/Stand/", 1, 5);
	m_AStand->AddContinueFrame(L"Resource/Kyo/Stand/", 5, 1);

	m_ASit = new Animation();
	m_ASit->Init(1, 2, this);
	m_ASit->SetAnimEndWithFrame(1);
	m_ASit->SetFrameZeroIsEnd(0);
	m_ASit->AddFrame(L"Resource/Kyo/Sit/1.png");
	m_ASit->AddFrame(L"Resource/Kyo/Sit/2.png");

	m_ALeft = new Animation();
	m_ALeft->Init(1, 8, this);
	m_ALeft->AddContinueFrame(L"Resource/Kyo/MoveLeft/", 1, 10);

	m_ARight = new Animation();
	m_ARight->Init(1, 8, this);
	m_ARight->AddContinueFrame(L"Resource/Kyo/MoveLeft/", 1, 10);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	FightObject::Update(deltaTime);

	switch (m_State)
	{
	case State::STAND:
		if (InputSystem->GetKey('S') == KeyState::PRESS)
		{
			m_State = State::SIT;
		}
		break;

	case State::SIT:
		if (InputSystem->GetKey('S') == KeyState::NONE)
		{
			m_State = State::STAND;
			m_ASit->Set();
		}
		break;

	case State::MOVE:
		if (InputSystem->GetKey('A') == KeyState::NONE)
			m_State = State::STAND;

		if (InputSystem->GetKey('D') == KeyState::NONE)
			m_State = State::STAND;
		break;
	}

	if (InputSystem->GetKey('H') == KeyState::UP)
	{
		m_State = State::PUNCH;
		m_bPunched = true;
	}

	if (InputSystem->GetKey('G') == KeyState::UP)
	{
		m_State = State::KICK;
	}

	if (m_State != State::SIT && m_State != State::PUNCH && m_State != State::KICK) 
		Move();

}

void Player::Render()
{
	FightObject::Render();
}

void Player::Punch()
{
	
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
	if (InputSystem->GetKey('D') == KeyState::PRESS)
	{
		Translate(5.f, 0.f);
		m_State = State::MOVE;
		m_Direction = Direction::RIGHT;
	}
	if (InputSystem->GetKey('A') == KeyState::PRESS)
	{
		Translate(-5.f, 0.f);
		m_State = State::MOVE;
		m_Direction = Direction::LEFT;
	}
	if (InputSystem->GetKey('W') == KeyState::PRESS)
	{
		
	}



}
