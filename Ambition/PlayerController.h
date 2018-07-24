#pragma once

enum KEYTYPE
{
	A,
	B
};

class PlayerController : public Controller
{
public:
	PlayerController(KEYTYPE Type);
	~PlayerController();

private:
	KEY m_Key;

public:
	bool IsLeftMove();
	bool IsRightMove();
	bool IsJump();
	bool IsPunch();
	bool IsKick();
	bool IsJumpPunch();
	bool IsJumpKick();
};