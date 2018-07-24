#pragma once
enum class State
{
	MOVE,
	PUNCH,
	BLOCK,
	KICK,
	JUMP,
	JUMP_PUNCH,
	JUMP_KICK,
	SIT,
	STAND
};

enum class Direction
{
	LEFT,
	RIGHT,
	NONE
};


class FightAnim
{
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

	FightAnim() {
		m_AJump = new Animation();
		m_ASit = new Animation();
		m_ABlock = new Animation();
		m_AStand = new Animation();
		m_ALeft = new Animation();
		m_ARight = new Animation();
		m_APunch = new Animation();
		m_AKick = new Animation();
		m_AJumpPunch = new Animation();
		m_AJumpKick = new Animation();
	}

	~FightAnim() {

	}

};

class Fighter : public GameObject
{
protected:
	Controller* m_Control;
	FightAnim* m_Anims;
	State m_State;
	Direction m_Direction;
	KEYTYPE m_KeyType;

	wstring m_PunchCombo;
	wstring m_KickCombo;
	wstring m_SpecialCombo;

public:
	Fighter();
	virtual ~Fighter();

	void SetKeyType(KEYTYPE type) {
		m_KeyType = type;
	}

	virtual void Update(float deltaTime);
	virtual void Render();

	void Input();

};