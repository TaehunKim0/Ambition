#include "stdafx.h"
#include "PlayerController.h"

PlayerController::PlayerController(KEYTYPE type)
{
	if (type == KEYTYPE::A)
	{
		m_Key.BLOCK = 'Y';
		m_Key.JUMP = 'W';
		m_Key.KICK = 'G';
		m_Key.PUNCH = 'H';
		m_Key.MOVELEFT = 'A';
		m_Key.MOVERIGHT = 'D';
		m_Key.SIT = 'S';
		m_Key.BACKDASH = 'Q';

		CMgr->SetPunchKick('H', 'G');
		CMgr->SetLeftRight('A', 'D');
	}

	else if (type == KEYTYPE::B)
	{
		m_Key.BLOCK = 'O';
		m_Key.JUMP = VK_UP;
		m_Key.KICK = 'I';
		m_Key.PUNCH = 'U';
		m_Key.MOVELEFT = VK_LEFT;
		m_Key.MOVERIGHT = VK_RIGHT;
		m_Key.SIT = VK_DOWN;
		m_Key.BACKDASH = 'O';

		CMgr->SetPunchKick('U', 'I');
		CMgr->SetLeftRight(VK_LEFT, VK_RIGHT);
	}
}

PlayerController::~PlayerController()
{
}

bool PlayerController::IsPunch()
{
	if(IInput->GetKey(m_Key.PUNCH) == KeyState::DOWN)
	{
		CMgr->AddCommand(m_Key.PUNCH);
		return true;
	}
	return false;
}

bool PlayerController::IsKick()
{
	if (IInput->GetKey(m_Key.KICK) == KeyState::DOWN)
	{
		CMgr->AddCommand(m_Key.KICK);
		return true;
	}
	return false;
}

bool PlayerController::IsJump()
{
	if (IInput->GetKey(m_Key.JUMP) == KeyState::DOWN)
	{
		return true;
	}
	return false;
}

bool PlayerController::IsSit()
{
	if (IInput->GetKey(m_Key.SIT) == KeyState::PRESS)
	{
		return true;
	}
	return false;
}

bool PlayerController::IsJumpPunch()
{
	return false;
}

bool PlayerController::IsJumpKick()
{
	return false;
}

bool PlayerController::IsBlock()
{
	if (IInput->GetKey(m_Key.BLOCK) == KeyState::PRESS)
	{
		return true;
	}
	return false;
}

bool PlayerController::IsMoveLeft()
{
	if (IInput->GetKey(m_Key.MOVELEFT) == KeyState::DOWN)
	{
		CMgr->AddCommand(m_Key.MOVELEFT);
	}

	if (IInput->GetKey(m_Key.MOVELEFT) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}

bool PlayerController::IsMoveRight()
{
	if (IInput->GetKey(m_Key.MOVERIGHT) == KeyState::DOWN)
	{
		CMgr->AddCommand(m_Key.MOVERIGHT);
	}

	if (IInput->GetKey(m_Key.MOVERIGHT) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}