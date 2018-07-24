#include "stdafx.h"
#include "FightObject.h"


FightObject::FightObject() :
	m_bCanMove(1)
	, m_State(State::STAND)
	, m_iAttackDelay(0)
	, m_Direction(Direction::NONE)
	, m_bPunched(0)
	, m_bJumped(0)
	, m_fJump_Accel(1.f)
	, m_fJumpSpeed(15.f)
	, m_bAttacked(0)
	, m_bJumpPunched(0)
{
}

FightObject::~FightObject()
{
}

void FightObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	switch (m_State)
	{
	case State::MOVE:
		if(m_Direction == Direction::LEFT)
			if (m_ALeft)
				m_ALeft->Update(deltaTime);

		if(m_Direction == Direction::RIGHT)
			if (m_ARight)
				m_ARight->Update(deltaTime);

		break;

	case State::PUNCH:
		if(m_APunch)
			m_APunch->Update(deltaTime);

		if (m_APunch->m_bEnd)
		{
			m_APunch->m_bEnd = 0;
			m_State = State::STAND;
			m_bPunched = false;
			m_bAttacked = false;
			m_bJumpPunched = false;
		}

		break;

	case State::JUMP_PUNCH:
		m_bJumpPunched = true;

		if (m_AJumpPunch)
			m_AJumpPunch->Update(deltaTime);

		if (m_AJumpPunch->m_bEnd)
		{
			m_State = State::JUMP;
			m_bAttacked = false;
			m_AJumpPunch->Set();
			m_AJump->SetCurrentFrame(m_AJump->m_iMiddleFrame);
			m_AJump->m_bAnimMiddle = true;
		}

		break;

	case State::KICK:
		if (m_AKick)
			m_AKick->Update(deltaTime);

		if (m_AKick->m_bEnd)
		{
			m_AKick->m_bEnd = 0;
			m_State = State::STAND;
			m_bAttacked = false;
		}
		break;

	case State::JUMP_KICK:
		m_bJumpKicked = true;

		if (m_AJumpKick)
			m_AJumpKick->Update(deltaTime);

		if (m_AJumpKick->m_bEnd)
		{
			m_State = State::JUMP;
			m_bAttacked = false;
			m_AJumpKick->Set();
			m_AJump->SetCurrentFrame(m_AJump->m_iMiddleFrame);
			m_AJump->m_bAnimMiddle = true;
		}

		break;

	case State::JUMP:
		if (m_AJump)
			m_AJump->Update(deltaTime);

		if (m_AJump->m_bAnimMiddle == false)
		{
			//m_fJumpSpeed += m_fJump_Accel;
			m_vPosition.y -= m_fJumpSpeed;
		}

		else
		{
			if (m_AJump->m_bEnd == false)
				m_vPosition.y += m_fJumpSpeed;
			else
				printf("aa");
		}

		if (m_AJump->m_bEnd)
		{
			m_AJump->m_bEnd = 0;
			m_State = State::STAND;
			m_bJumped = false;
			m_AJump->Set();
		}

		break;
		
	case State::SIT:
		if (m_ASit)
			m_ASit->Update(deltaTime);
		break;

	case State::BLOCK:
		if (m_ABlock)
			m_ABlock->Update(deltaTime);
		break;

	case State::STAND:
		if (m_AStand)
			m_AStand->Update(deltaTime);
		break;
	}




}

void FightObject::Render()
{
	GameObject::Render();

	switch (m_State)
	{
	case State::MOVE:
		if (m_Direction == Direction::LEFT)
			if (m_ALeft)
				m_ALeft->Render();

		if (m_Direction == Direction::RIGHT)
			if (m_ARight)
				m_ARight->Render();

		break;

	case State::PUNCH:
		if (m_APunch)
			m_APunch->Render();
		break;

	case State::JUMP_PUNCH:
		if (m_AJumpPunch)
			m_AJumpPunch->Render();

		break;

	case State::KICK:
		if (m_AKick)
			m_AKick->Render();
		break;

	case State::JUMP_KICK:
		if (m_AJumpKick)
			m_AJumpKick->Render();
		break;

	case State::JUMP:
		if (m_AJump)
			m_AJump->Render();
		break;

	case State::SIT:
		if (m_ASit)
			m_ASit->Render();
		break;

	case State::BLOCK:
		if (m_ABlock)
			m_ABlock->Render();
		break;

	case State::STAND:
		if (m_AStand)
			m_AStand->Render();
		break;
	}
}

void FightObject::Punch()
{
}

void FightObject::Kick()
{
}

void FightObject::Sit()
{
}

void FightObject::Block()
{
}

void FightObject::Jump()
{
}

void FightObject::SetKey(int attack, int kick, int jump, int sit, int block)
{
}

void FightObject::Move()
{
}
