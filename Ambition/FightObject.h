#pragma once

enum class State
{
	ATTACK,
	BLOCK,
	JUMP,
	SIT,
	NONE
};


class FightObject : public GameObject
{
public:
	State m_State;
	bool m_bCanMove;

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