#include "stdafx.h"
#include "FightObject.h"


FightObject::FightObject() :
	m_bCanMove(1)
	, m_State(State::STAND)
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
	case State::PUNCH:
		if(m_APunch)
			m_APunch->Update(deltaTime);
		break;

	case State::KICK:
		if (m_AKick)
			m_AKick->Update(deltaTime);
		break;

	case State::JUMP:
		if (m_AJump)
			m_AJump->Update(deltaTime);
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
	case State::PUNCH:
		if (m_APunch)
			m_APunch->Render();
		break;

	case State::KICK:
		if (m_AKick)
			m_AKick->Render();
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

void FightObject::Move()
{
}
