#pragma once

class FightObject : public GameObject
{
public:
	State m_State;
	Direction m_Direction;

	bool m_bCanMove;
	int m_iAttackDelay;
	
	float m_fJump_Accel;
	float m_fJumpSpeed;

public:
	bool m_bPunched;
	bool m_bJumped;

	bool m_bAttacked;
	bool m_bJumpPunched;
	bool m_bJumpKicked;

public:
	Animation * m_AJump;
	Animation * m_ASit;
public:
	Animation * m_ABlock;
	Animation * m_AStand;
public:
	Animation * m_ALeft;
	Animation * m_ARight;
	
public:
	Animation * m_APunch;
	Animation * m_AKick;

	Animation* m_AJumpPunch;
	Animation* m_AJumpKick;

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