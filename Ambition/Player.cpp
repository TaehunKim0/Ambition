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

	m_AJump = new Animation();
	m_AJump->Init(1, 5, this);
	m_AJump->SetAnimEndWithFrame(1);
	m_AJump->AddContinueFrame(L"Resource/Kyo/Jump/", 1, 7);

	m_AJumpPunch = new Animation();
	m_AJumpPunch->Init(1, 2, this);
	m_AJumpPunch->SetAnimEndWithFrame(1);
	m_AJumpPunch->AddContinueFrame(L"Resource/Kyo/JumpPunch/", 4, 10);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	FightObject::Update(deltaTime);

	bool isSit = (m_State == State::SIT);
	bool isPunch = (m_State == State::PUNCH);
	bool isKick = (m_State == State::KICK);


	switch (m_State)
	{
	case State::STAND:
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

	if(!isKick && !isSit && m_State != State::JUMP_PUNCH)
		if (InputSystem->GetKey('H') == KeyState::UP)
		{
			if (m_State == State::JUMP)
			{
				if(m_bJumpPunched == false)
					m_State = State::JUMP_PUNCH;
			}
			else
				m_State = State::PUNCH;

			m_bPunched = true;
			m_bAttacked = true;
		}
	
	if (!isPunch && !isSit && m_State != State::JUMP_KICK)
		if (InputSystem->GetKey('G') == KeyState::UP)
		{
			if (m_State == State::JUMP)
			{
				if (m_bJumpKicked == false)
					m_State = State::JUMP_KICK;
			}
			else
				m_State = State::KICK;

			m_State = State::KICK;
			m_bAttacked = true;
		}

	if (!isSit && !isPunch && !isKick) 
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
	bool isSit = (m_State == State::SIT);
	bool isPunch = (m_State == State::PUNCH);
	bool isKick = (m_State == State::KICK);

	if(m_bAttacked == false && m_bJumped == false)
		if (InputSystem->GetKey('S') == KeyState::PRESS)
		{
			m_State = State::SIT;
		}

	if (!isSit && m_State != State::PUNCH && m_State != State::KICK)
	{
		if (InputSystem->GetKey('D') == KeyState::PRESS)
		{
			Translate(5.f, 0.f);
			if (m_State != State::JUMP && m_State != State::JUMP_PUNCH)
			{
				m_State = State::MOVE;
				m_Direction = Direction::RIGHT;
			}
		}
		if (InputSystem->GetKey('A') == KeyState::PRESS)
		{
			Translate(-5.f, 0.f);
			if (m_State != State::JUMP && m_State != State::JUMP_PUNCH)
			{
				m_State = State::MOVE;
				m_Direction = Direction::LEFT;
			}
		}

	}

	if(m_bAttacked == false && m_bJumped == false)
		if (InputSystem->GetKey('W') == KeyState::PRESS)
		{
			m_State = State::JUMP;
			m_bJumped = true;
		}
}