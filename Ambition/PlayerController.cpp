#include "stdafx.h"
#include "PlayerController.h"

wstring MOVELEFT;
wstring MOVERIGHT;
wstring PUNCH;
wstring BLOCK;
wstring KICK;
wstring JUMP;
wstring SIT;


PlayerController::PlayerController(KEYTYPE Type)
{
	if (Type == KEYTYPE::A)
	{
		m_Key.Init('A', 'D', 'H', 'X', 'G', 'W', 'S');
	}

	else if (Type == KEYTYPE::B)
	{
		m_Key.Init(VK_LEFT, VK_RIGHT, 5, 9, 4, VK_UP, VK_DOWN);
	}
}

PlayerController::~PlayerController()
{
}

bool PlayerController::IsLeftMove()
{
	if (InputSystem->GetKey(m_Key.MOVELEFT) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}

bool PlayerController::IsRightMove()
{
	if (InputSystem->GetKey(m_Key.MOVERIGHT) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}

bool PlayerController::IsJump()
{
	if (InputSystem->GetKey(m_Key.JUMP) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}

bool PlayerController::IsPunch()
{
	if (InputSystem->GetKey(m_Key.PUNCH) == KeyState::PRESS)
	{
		return true;
	}

	return false;
}

bool PlayerController::IsKick()
{
	if (InputSystem->GetKey(m_Key.KICK) == KeyState::PRESS)
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
