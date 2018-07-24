#include "stdafx.h"
#include "Fighter.h"

Fighter::Fighter()
	: m_State(State::STAND)
	, m_Direction(Direction::NONE)
{
	m_Anims = new FightAnim();
}

Fighter::~Fighter()
{
}


void Fighter::Input()
{
	switch (m_State)
	{
	case State::STAND:

		break;
		
	case State::SIT:

		break;
	}
}


void Fighter::Update(float deltaTime)
{
	switch (m_State)
	{
	case State::MOVE:
		if (m_Direction == Direction::LEFT)
			m_Anims->m_ALeft->Update(deltaTime);
		else if (m_Direction == Direction::RIGHT)
			m_Anims->m_ARight->Update(deltaTime);

		break;

	case State::PUNCH:
		m_Anims->m_APunch->Update(deltaTime);
		break;

	case State::JUMP_PUNCH:
		m_Anims->m_AJumpPunch->Update(deltaTime);
		break;

	case State::KICK:
		m_Anims->m_AKick->Update(deltaTime);
		break;

	case State::JUMP_KICK:
		m_Anims->m_AJumpKick->Update(deltaTime);
		break;

	case State::JUMP:
		m_Anims->m_AJump->Update(deltaTime);
		break;

	case State::SIT:
		m_Anims->m_ASit->Update(deltaTime);
		break;

	case State::BLOCK:
		m_Anims->m_ABlock->Update(deltaTime);
		break;

	case State::STAND:
		m_Anims->m_AStand->Update(deltaTime);
		break;
	}

	Input();


}

void Fighter::Render()
{
	switch (m_State)
	{
	case State::MOVE:
		if (m_Direction == Direction::LEFT)
			m_Anims->m_ALeft->Render();
		else if (m_Direction == Direction::RIGHT)
			m_Anims->m_ARight->Render();

		break;

	case State::PUNCH:
		m_Anims->m_APunch->Render();
		break;

	case State::JUMP_PUNCH:
		m_Anims->m_AJumpPunch->Render();
		break;

	case State::KICK:
		m_Anims->m_AKick->Render();
		break;

	case State::JUMP_KICK:
		m_Anims->m_AJumpKick->Render();
		break;

	case State::JUMP:
		m_Anims->m_AJump->Render();
		break;

	case State::SIT:
		m_Anims->m_ASit->Render();
		break;

	case State::BLOCK:
		m_Anims->m_ABlock->Render();
		break;

	case State::STAND:
		m_Anims->m_AStand->Render();
		break;
	}
}
