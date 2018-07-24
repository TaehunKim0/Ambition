#pragma once

typedef struct KEY
{
public:
	int MOVELEFT;
	int MOVERIGHT;
	int PUNCH;
	int BLOCK;
	int KICK;
	int JUMP;
	int SIT;

public:
	void Init(int l, int r, int p, int b, int k, int j, int s)
	{
		MOVELEFT = l;
		MOVERIGHT = r;
		PUNCH = p;
		KICK = k;
		BLOCK = b;
		JUMP = j;
		SIT = s;
	}

}KEY;

struct Command
{
	int Key;
	int time;
};

class Controller
{
public:
	Controller();
	virtual ~Controller();
	std::queue<Command> CommnadBuffer;

public:
	virtual bool IsLeftMove() { return false; };
	virtual bool IsRightMove() { return false; };
	virtual bool IsJump() { return false; };
	virtual bool IsPunch() { return false; };
	virtual bool IsKick() { return false; };
	virtual bool IsJumpPunch() { return false; };
	virtual bool IsJumpKick() { return false; };
};

