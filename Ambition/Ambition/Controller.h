#pragma once

typedef struct Key
{
	int MOVELEFT;
	int MOVERIGHT;
	int SIT;
	int PUNCH;
	int KICK;
	int BLOCK;
	int JUMP;
	int BACKDASH;
}KEY;


enum class State
{
	STAND,
	MOVE,
	SIT,
	PUNCH,
	KICK,
	BLOCK,
	JUMP,
	HIT,
	NONE
};


class Controller
{
public:
	Controller();
	~Controller();

	CommandMgr* CMgr;

	KEY m_Key;
	void AddPattern();
	void RunAI();

	std::queue<State> m_AIPattern;
	State GetPattern();

public:
	virtual bool IsPunch() { return false; };
	virtual bool IsKick() { return false; };
	virtual bool IsJump() { return false; };
	virtual bool IsSit() { return false; };
	virtual bool IsJumpPunch() { return false; };
	virtual bool IsJumpKick() { return false; };
	virtual bool IsBlock() { return false; };
	virtual bool IsMoveLeft() { return false; };
	virtual bool IsMoveRight() { return false; };
	virtual bool IsNoneMove() { return false; }
};