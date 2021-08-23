#include "stdafx.h"
#include "Fighter.h"

Fighter::Fighter(PlayerType type, KEYTYPE key)
{
	BackDashed = false;
	m_Health = 100;
	m_JumpSpeed = 3.f;
	HitDelay = 0;
	one = false;
	m_UpCollision = new Collision();
	m_DownCollision = new Collision();
	m_MidCollision = new Collision();

	UpCollideBox = Sprite::Create("Resource/Collide.png");
	MidCollideBox = Sprite::Create("Resource/Collide.png");
	DownCollideBox = Sprite::Create("Resource/Collide.png");

	Collider = Sprite::Create("Resource/Collider.png");

	m_CanHit = true;

	m_Anim = new Animations();
	m_Anim->m_Parent = this;
	m_State = State::STAND;

	if (type == PlayerType::Player1)
	{
		m_HpUI = Sprite::Create("Resource/UI/1.png");
		m_Control = new PlayerController(KEYTYPE::A);
		m_Type = PlayerType::Player1;
		m_HpUI->SetPos(466, 47);
	}

	else if (type == PlayerType::Player2)
	{
		m_HpUI = Sprite::Create("Resource/UI/2.png");
		m_Control = new PlayerController(KEYTYPE::B);
		m_Type = PlayerType::Player2;
		m_HpUI->SetPos(1057, 47);
	}

	else if (type == PlayerType::AI)
	{
		m_HpUI = Sprite::Create("Resource/UI/2.png");
		m_Control = new AIController();
		m_Type = PlayerType::AI;
		m_HpUI->SetPos(1057, 47);
	}
	
	m_Direction = Direction::RIGHT;
	m_AttackDelay = 30.f;

	m_State = State::STAND;

	OMgr->Add(UpCollideBox);
	OMgr->Add(MidCollideBox);
	OMgr->Add(DownCollideBox);
	OMgr->Add(Collider);

	Collider->m_Active = false;
	UpCollideBox->m_Active = false;
	MidCollideBox->m_Active = false;
	DownCollideBox->m_Active = false;

	m_RightDash = false;
	m_LeftDash = false;
}

Fighter::~Fighter()
{
}

void Fighter::AIControl()
{
	switch (m_State)
	{
	case State::STAND:
		printf("AI STAND\n");

		if (Enemy)
		{
			if (m_Position.x >= Enemy->m_Position.x)
			{
				if (m_Position.x <= Enemy->m_Position.x + 100)
				{
					int ran = Random(2, 6);
					//ran = 1;

					switch (ran)
					{
					case 1:
						if (m_IsAttacked == false)
						{
							if (m_Type == PlayerType::Player1)
							{
								Translate(100.f, 0.f);
							}

							else
							{
								Translate(-100.f, 0.f);
							}
						}

						m_State = State::PUNCH;
						m_IsAttacked = true;
						break;

					case 2:

						break;

					case 3:

						break;

					case 4:

						break;

					case 5:

						break;

					case 6:

						break;

					}
				}

				else
				{
					m_Position.x -= 3.f;
				}
			}
		}

		break;
	case State::SIT:
		printf("AI SIT\n");
		break;
	case State::PUNCH:
		printf("AI PUNCH\n");

		if (m_Anim->APunch->m_End)
		{
			if (m_Type == PlayerType::Player1)
			{
				Translate(-100.f, 0.f);
			}
			else
			{
				Translate(100.f, 0.f);
			}

			m_LeftDash = false;
			m_RightDash = false;

			m_IsAttacked = false;
			m_State = State::STAND;
			m_Anim->APunch->m_End = false;
		}

		break;
	case State::KICK:
		printf("AI KICK\n");
		break;
	case State::BLOCK:
		printf("AI BLOCK\n");
		break;
	case State::MOVE:
		printf("AI MOVE\n");
		break;
	case State::JUMP:
		printf("AI JUMP\n");
		break;
	}

	//if(m_State == State::STAND)
	//	m_State = m_Control->GetPattern();

}

void Fighter::Control()
{
	UpCollideBox->m_Position = D3DXVECTOR2(m_UpCollision->m_Rect.left, m_UpCollision->m_Rect.top);
	MidCollideBox->m_Position = D3DXVECTOR2(m_MidCollision->m_Rect.left, m_MidCollision->m_Rect.top);
	DownCollideBox->m_Position = D3DXVECTOR2(m_DownCollision->m_Rect.left, m_DownCollision->m_Rect.top);

	switch (m_State)
	{
	case State::STAND:
		//m_Control->CMgr->m_Command.clear();

		AllUseNotCollide();
		break;
	case State::SIT:
		AllUseNotCollide();
		break;
	case State::PUNCH:
		m_UseUpCollide = true;
		break;
	case State::KICK:
		m_UseMidCollide = true;
		break;
	case State::BLOCK:
		AllUseNotCollide();
		break;
	case State::MOVE:
		AllUseNotCollide();
		break;
	case State::JUMP:
		AllUseNotCollide();
		break;
	}
}

void Fighter::PlayerControl()
{
	//SetRect(&m_Collision, m_Position.x, m_Position.y, m_Position.x + m_Size.x, m_Position.y + m_Size.y)

	printf("LEFT DASH : %d\n", m_LeftDash);
	printf("RIGHT DASH : %d\n", m_RightDash);

	if (m_LeftDash)
	{
		if (IInput->GetKey(m_Control->m_Key.MOVELEFT) == KeyState::NONE)
		{
			m_LeftDash = false;
		}
	}

	if (m_RightDash)
	{
		if (IInput->GetKey(m_Control->m_Key.MOVERIGHT) == KeyState::NONE)
		{
			m_RightDash = false;
		}
	}

	if (m_Control->CMgr->m_Command.size() > 2)
		if (m_Control->CMgr->IsPunchCommand())
		{
			m_UsePunchCombo = true;
			printf("ÁÖ¸Ô ÄÞº¸\n");
			m_Control->CMgr->m_Command.erase(m_Control->CMgr->m_Command.cbegin());
		}

	if (m_Control->CMgr->m_Command.size() > 2)
		if (m_Control->CMgr->IsKickCommand())
		{
			m_UseKickCombo = true;
			printf("¹ßÂ÷±â ÄÞº¸\n");
			m_Control->CMgr->m_Command.erase(m_Control->CMgr->m_Command.cbegin());
		}

	if (m_Control->CMgr->m_Command.size() > 1)
		if (m_Control->CMgr->IsBlockCommand())
		{
			m_State = State::BLOCK;
			printf("ºí·ÏÄ¿¸Çµå\n");
			m_Control->CMgr->m_Command.erase(m_Control->CMgr->m_Command.cbegin());

			return;
		}

	if (m_Control->CMgr->m_Command.size() > 1)
		if (m_Control->CMgr->IsRightDashCommand())
		{
			if (m_RightDash == false)
			{
				m_RightDash = true;
				m_State = State::MOVE;
				m_Control->CMgr->m_Command.clear();
			}
		}
	
	if (m_Control->CMgr->m_Command.size() > 1)
		if (m_Control->CMgr->IsLeftDashCommand())
		{
			if (m_LeftDash == false)
			{
				m_State = State::MOVE;
				m_LeftDash = true;
				m_Control->CMgr->m_Command.clear();
			}
		}

	switch (m_State)
	{
	case State::MOVE:
		printf("MOVE\n");

		BackDashed = false;

		if (IInput->GetKey(m_Control->m_Key.BACKDASH) == KeyState::DOWN)
		{
			BackDashed = true;
			if (m_Type == PlayerType::Player1)
			{
				Translate(-100.f, 0.f);
			}
			else
			{
				Translate(100.f, 0.f);
			}
		}


		if (m_LeftDash)
			Translate(-7.f, 0.f);
		else
			if (m_Control->IsMoveLeft())
				Translate(-3.f, 0.f);
		
		if (m_RightDash)
			Translate(7.f, 0.f);
		else
			if(m_Control->IsMoveRight())
				Translate(3.f, 0.f);

		if (m_Control->IsNoneMove())
		{
			m_State = State::STAND;
		}

		if(m_CanHit)
			if (m_Control->IsPunch())
			{
				if (m_Type == PlayerType::Player1)
				{
					Translate(100.f, 0.f);
				}
				else
				{
					Translate(-100.f, 0.f);
				}

				m_State = State::PUNCH;
				m_IsAttacked = true;
				m_CanHit = false;
			}

		if (m_Control->IsSit())
		{
			m_State = State::SIT;
		}

		if (m_Control->IsJump())
		{

		}

		break;

	case State::STAND:
		printf("STAND\n");

		BackDashed = false;

		if (IInput->GetKey(m_Control->m_Key.BACKDASH) == KeyState::DOWN)
		{
			BackDashed = true;
			if (m_Type == PlayerType::Player1)
			{
				Translate(-100.f, 0.f);
			}
			else
			{
				Translate(100.f, 0.f);
			}
		}

		if (m_Control->IsMoveLeft())
		{
			m_State = State::MOVE;
			m_Direction = Direction::LEFT;
		}
		if (m_Control->IsMoveRight())
		{
			m_State = State::MOVE;
			m_Direction = Direction::RIGHT;
		}

		if(m_CanHit)
			if (m_Control->IsPunch())
			{
				if (m_Type == PlayerType::Player1)
				{
					Translate(100.f, 0.f);
				}
				else
				{
					Translate(-100.f, 0.f);
				}
				m_CanHit = false;
				m_State = State::PUNCH;
				m_IsAttacked = true;
			}


		if(m_Control->IsSit())
		{
			m_State = State::SIT;
		}

		if (m_Control->IsJump())
		{

		}

		break;

	case State::JUMP:
		printf("JUMP\n");

		if (m_Control->IsMoveLeft())
		{
			Translate(-3.f, 0.f);
			m_Direction = Direction::LEFT;
		}
		if (m_Control->IsMoveRight())
		{
			Translate(3.f, 0.f);
			m_Direction = Direction::RIGHT;
		}

		if (m_Control->IsPunch())
		{

		}

		break;

	case State::PUNCH:
		printf("PUNCH\n");
		//Á¡ÇÁ ÆÝÄ¡, ¾É±â ÆÝÄ¡ÀÏ¶§ Ãæµ¹Ã¼ »ç¿ë ´Ù¸§

		if(m_CanHit)
			if (m_IsAttacked == false)
			{
				if (m_Control->IsPunch())
				{

				}
				if (m_Control->IsKick())
				{

				}
			}

		break;

	case State::SIT:
		if (IInput->GetKey(m_Control->m_Key.SIT) == KeyState::NONE)
		{
			m_Anim->ASit->m_End = false;
			m_Anim->ASit->m_CurrentFrame = 0;
			m_Anim->ASit->BAutoWhenEnd = 0;
			m_Anim->ASit->m_AutoPlay = 1;

			m_Anim->ASitt->m_End = false;
			m_Anim->ASitt->m_CurrentFrame = 0;

			m_State = State::STAND;
		}

		break;

	case State::BLOCK:
		printf("BLOCK\n");

		if (one == false)
		{
			if (m_Type == PlayerType::Player1)
			{
				Translate(-100.f, 0.f);
				one = true;
			}
			else
			{
				Translate(100.f, 0.f);
				one = true;
			}
		}
		
		if (IInput->GetKey(m_Control->m_Key.PUNCH) != KeyState::PRESS)
		{
			one = false;
			m_Control->CMgr->m_Command.clear();
			m_State = State::STAND;
		}
		else if (IInput->GetKey(m_Control->m_Key.PUNCH) != KeyState::PRESS)
		{
			one = false;
			m_Control->CMgr->m_Command.clear();
			m_State = State::STAND;
		}
		break;
	}
}

void Fighter::Update(float deltaTime)
{
	if (IInput->GetKey(VK_SPACE) == KeyState::UP)
	{
		IsAttackedFromOther();
	}

	if (!m_DontMove)
	{
		if (m_Control->CMgr->m_Command.size() > 3)
			m_Control->CMgr->m_Command.erase(m_Control->CMgr->m_Command.cbegin());


		Control();

		if (m_Type == PlayerType::Player1 || m_Type == PlayerType::Player2)
			PlayerControl();
		else if (m_Type == PlayerType::AI)
		{
			AIControl();
		}
	}

	if (m_CanHit == false)
	{
		HitDelay++;

		if (HitDelay > 30)
		{
			m_CanHit = true;
			HitDelay = 0;
		}
	}
	
	switch (m_State)
	{
		
	/*case State::BLOCK:
		if (m_Anim->ABlock)
			m_Anim->ABlock->Update(deltaTime);
		break;
	case State::JUMP:
		if (m_Anim->AJump)
			m_Anim->AJump->Update(deltaTime);
		break;*/
	case State::MOVE:
		if (m_Anim->AMoveLeft)
			if(m_Direction == Direction::LEFT)
				m_Anim->AMoveLeft->Update(deltaTime);

		else if (m_Anim->AMoveRight)
			if (m_Direction == Direction::RIGHT)
				m_Anim->AMoveRight->Update(deltaTime);

		break;

	/*case State::KICK:
		if (m_Anim->AKick)
			m_Anim->AKick->Update(deltaTime);
		break;*/

	case State::PUNCH:
		if(m_Anim->APunch)
			m_Anim->APunch->Update(deltaTime);

		if (m_Anim->APunch->m_End)
		{
			if (m_Type == PlayerType::Player1)
			{
				Translate(-100.f, 0.f);
			}
			else
			{
				Translate(100.f, 0.f);
			}

			m_LeftDash = false;
			m_RightDash = false;

			m_IsAttacked = false;
			m_State = State::STAND;
			m_Anim->APunch->m_End = false;
		}

		break;
		
	case State::SIT:
		if (m_Anim->ASit && m_Anim->ASit->m_End == false)
			m_Anim->ASit->Update(deltaTime);
		else
			m_Anim->ASitt->Update(deltaTime);

		break;

	case State::STAND:
		if (m_Anim->AStand)
			m_Anim->AStand->Update(deltaTime);
		break;
		
	}
}

void Fighter::Render()
{
	switch (m_State)
	{
	//	case State::BLOCK:
	//		if (m_Anim->ABlock)
	//			m_Anim->ABlock->Render();
	//	break;
	//case State::JUMP:
	//	if (m_Anim->AJump)
	//	m_Anim->AJump->Render();
	//	break;
	case State::MOVE:
		if (m_Direction == Direction::LEFT)
			m_Anim->AMoveLeft->Render();
		else if (m_Direction == Direction::RIGHT)
			m_Anim->AMoveRight->Render();
		break;
	//case State::KICK:
	//	if (m_Anim->AKick)
	//	m_Anim->AKick->Render();
	//	break;
	case State::PUNCH:
		if (m_Anim->APunch)
		m_Anim->APunch->Render();
		break;
		
	case State::SIT:
		if (m_Anim->ASit && m_Anim->ASit->m_End == false)
			m_Anim->ASit->Render();
		else
			m_Anim->ASitt->Render();

		break;
	case State::STAND:
		if (m_Anim->AStand)
		m_Anim->AStand->Render();
		break;
		
	}
	
}