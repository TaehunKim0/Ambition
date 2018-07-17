#pragma once

enum class State
{
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
	bool m_bCanMove;

public:
	Animation * m_APunch;
	Animation * m_AKick;
	Animation * m_AJump;
	Animation * m_ASit;
	Animation * m_ABlock;
	Animation * m_AStand;

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

public:
	void Move();


};