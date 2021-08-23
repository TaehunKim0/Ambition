#pragma once


enum class Direction
{
	LEFT,
	RIGHT, 
	NONE
};

class Animations : public GameObject
{
public:
	Animation * AMoveLeft;
	Animation * AMoveRight;
	Animation * AStand;
	Animation * ASit;
	Animation * APunch;
	Animation * AKick;
	Animation * AJump;
	Animation * AJumpPunch;
	Animation * AJumpKick;
	Animation * ABlock;
	Animation * ASitt;
	Animation * AHit;

public:
	Animations() {
		AMoveLeft = new Animation();
		AMoveLeft->m_Parent = this;

		AHit = new Animation();
		AHit->m_Parent = this;

		AMoveRight = new Animation();
		AMoveRight->m_Parent = this;

		AStand = new Animation();
		AStand->m_Parent = this;

		ASit = new Animation();
		ASit->m_Parent = this;

		ASitt = new Animation();
		ASitt->m_Parent = this;

		APunch = new Animation();
		APunch->m_Parent = this;

		AKick = new Animation();
		AKick->m_Parent = this;

		AJump = new Animation();
		AJump->m_Parent = this;

		AJumpPunch = new Animation();
		AJumpPunch->m_Parent = this;

		AJumpKick = new Animation();
		AJumpKick->m_Parent = this;

		ABlock = new Animation();
		ABlock->m_Parent = this;

	}
};

enum class Character
{
	STEVEFOX,
	NAMIL,
	CHUNGYOUNG,
	NONE
};


enum class PlayerType
{
	Player1,
	Player2,
	AI,
	NONE
};


class Fighter : public GameObject
{
public:
	State m_State;
	Animations* m_Anim;
	Controller* m_Control;
	Direction m_Direction;
	PlayerType m_Type;

	Sprite* UpCollideBox;
	Sprite* MidCollideBox;
	Sprite* DownCollideBox;

	Sprite* Collider;

	Sprite* m_HpUI;

	bool BackDashed;

	Fighter* Enemy;
	void GetEnemy(Fighter* e) {
		Enemy = e;
	}

public:
	Collision * m_UpCollision;
	Collision * m_MidCollision;
	Collision * m_DownCollision;

public:
	int m_Health;

	int m_JumpSpeed;
	bool m_GetDoubleDamage;

	bool m_RightDash;
	bool m_LeftDash;

	bool one;
	bool m_UseUpCollide;
	bool m_UseMidCollide;
	bool m_UseDownCollide;

	void AllUseCollide() {
		m_UseUpCollide   = true;
		m_UseMidCollide  = true;
		m_UseDownCollide = true;
	}

	void AllUseNotCollide() {
		m_UseUpCollide = false;
		m_UseMidCollide = false;
		m_UseDownCollide = false;
	}

	bool m_CanHit;

	int HitDelay;

	int Random(int start, int last) {
		auto ran = (rand() % last) + start;
		return ran;
	}


public:
	bool m_IsAttacked;
	bool m_IsJumped;
	bool m_DontMove;

	bool m_UsePunchCombo;
	bool m_UseKickCombo;

	bool m_DelayTime;
	int m_AttackDelay;

public:
	Fighter(PlayerType type, KEYTYPE key);
	virtual ~Fighter();

	void AIControl();
	void Control();
	void PlayerControl();

	void Update(float deltaTime);
	void Render();

	void HpInit() {
		m_Health = 100;
		if (m_Type == PlayerType::Player1)
		{
			m_HpUI->DeltaDrawSize.x = 0;
			m_HpUI->SetPos(466, 47);
		}
		else if (m_Type == PlayerType::Player2 || m_Type == PlayerType::AI)
		{
			m_HpUI->DeltaDrawPosition.x = 0;
			m_HpUI->SetPos(1057, 47);
		}
	}

public:
	virtual void IsAttackedFromOther() 
	{
		if (m_CanHit)
		{
			if (m_GetDoubleDamage == false)
			{
				m_Health -= 10;

				if (m_Type == PlayerType::Player1)
				{
					m_HpUI->DeltaDrawSize.x -= 40;
				}
				else if (m_Type == PlayerType::Player2)
				{
					m_HpUI->DeltaDrawPosition.x += 40;
					m_HpUI->Translate(40, 0);
				}
				else if (m_Type == PlayerType::AI)
				{
					m_HpUI->DeltaDrawPosition.x += 40;
					m_HpUI->Translate(40, 0);
				}

			}
			else
			{
				m_Health -= 20;

				if (m_Type == PlayerType::Player1)
				{
					m_HpUI->DeltaDrawSize.x -= 40 * 2;
				}
				else if (m_Type == PlayerType::Player2)
				{
					m_HpUI->DeltaDrawPosition.x += 40 * 2;
					m_HpUI->Translate(40 *2, 0);
				}
				else if (m_Type == PlayerType::AI)
				{
					m_HpUI->DeltaDrawPosition.x += 40 * 2;
					m_HpUI->Translate(40 *2, 0);
				}

				m_GetDoubleDamage = false;
			}
			//m_State = State::HIT;

		

			m_CanHit = false;
		}
	}
};

