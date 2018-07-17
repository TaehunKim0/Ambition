#pragma once

enum class State
{
	MOVE,
	PUNCH,
	BLOCK,
	KICK,
	JUMP,
	SIT,
	STAND
};

enum class Direction
{
	LEFT,
	RIGHT,
	NONE
};

enum Key
{
	MOVELEFT,
	MOVERIGHT,
	PUNCH,
	BLOCK,
	KICK,
	JUMP,
	SIT,
	STAND
};

class FightObject : public GameObject
{
public:
	State m_State;
	Direction m_Direction;
	Key m_Key;

	bool m_bCanMove;
	int m_iAttackDelay;

public:
	bool m_bPunched;

public:
	Animation * m_APunch;
	Animation * m_AKick;
	Animation * m_AJump;
	Animation * m_ASit;
	Animation * m_ABlock;
	Animation * m_AStand;

	Animation * m_ALeft;
	Animation * m_ARight;

public:
	FightObject();
	virtual ~FightObject();

public:
	void Update(float deltaTime);
	void Render();

public:
	virtual void Punch();
	virtual void Kick();
	virtual void Sit();
	virtual void Block();
	virtual void Jump();

	virtual void SetKey(int attack, int kick, int jump, int sit, int block);

public:
	void Move();


};