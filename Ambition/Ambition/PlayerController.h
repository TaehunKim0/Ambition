#pragma once

enum class KEYTYPE
{
	A,
	B,
	NONE
};

class PlayerController : public Controller
{
public:
	PlayerController(KEYTYPE type);
	~PlayerController();

	virtual bool IsPunch();
	virtual bool IsKick();
	virtual bool IsJump();
	virtual bool IsSit();
	virtual bool IsJumpPunch();
	virtual bool IsJumpKick();
	virtual bool IsBlock();
	virtual bool IsMoveLeft();
	virtual bool IsMoveRight();
	virtual bool IsNoneMove() {
		if (IInput->GetKey(m_Key.MOVELEFT) == KeyState::NONE && IInput->GetKey(m_Key.MOVERIGHT) == KeyState::NONE)
			return true;

		return false;
	}
};

