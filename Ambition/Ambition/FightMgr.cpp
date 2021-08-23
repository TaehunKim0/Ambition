#include "stdafx.h"
#include "FightMgr.h"
#include"Characters.h"

FightMgr::FightMgr()
{
	time = 0;
	BackUI = Sprite::Create("Resource/1.png");
	BackUI->SetPos(321,1);
	BackUI->m_Active = false;

	m_Time = new TimeUI();
	m_Time->SetAnim();
	RoundCount = 0;
	Ball = Sprite::Create("Resource/ball.png");
	Ball2 = Sprite::Create("Resource/ball.png");
	Ball3 = Sprite::Create("Resource/ball.png");
	Ball4 = Sprite::Create("Resource/ball.png");
	Ball5 = Sprite::Create("Resource/ball.png");
	Ball6 = Sprite::Create("Resource/ball.png");

	Player1Win = Sprite::Create("Resource/Player1Win.png");
	Player2Win = Sprite::Create("Resource/Player2Win.png");

	RoundEnd = false;


	Ball->m_Active = false;
	Ball2->m_Active = false;
	Ball3->m_Active = false;
	Ball4->m_Active = false;
	Ball5->m_Active = false;
	Ball6->m_Active = false;

	Player1Win->m_Active = false;
	Player2Win->m_Active = false;

	Player1WinCount = 0;
	Player2WinCount = 0;
}

FightMgr::~FightMgr()
{
}

void FightMgr::CreateCharacter(Character p1, Character p2, bool ai)
{
	switch (ai)
	{
	case 0:
		switch (p1)
		{
		case Character::STEVEFOX:
			Player1 = new SteveFox(PlayerType::Player1, KEYTYPE::A);
			Player1->m_Direction = Direction::RIGHT;
			break;

		case Character::NAMIL:
			Player1 = new NamIl(PlayerType::Player1, KEYTYPE::A);
			Player1->m_Direction = Direction::RIGHT;
			break;
		}

		switch (p2)
		{
		case Character::STEVEFOX:
			Player2 = new SteveFox(PlayerType::Player2, KEYTYPE::B);
			Player2->m_Direction = Direction::LEFT;
			break;

		case Character::NAMIL:
			Player2 = new NamIl(PlayerType::Player2, KEYTYPE::B);
			Player2->m_Direction = Direction::LEFT;
			break;
		}
		break;

	case 1:
		switch (p1)
		{
		case Character::STEVEFOX:
			Player1 = new SteveFox(PlayerType::Player1, KEYTYPE::A);
			Player1->m_Direction = Direction::RIGHT;
			break;

		case Character::NAMIL:
			Player1 = new NamIl(PlayerType::Player1, KEYTYPE::A);
			Player1->m_Direction = Direction::RIGHT;
			break;
		}

		Player2 = new SteveFox(PlayerType::AI, KEYTYPE::B);
		Player2->m_Direction = Direction::LEFT;
		break;
	}

	OMgr->Add(BackUI);
	OMgr->Add(m_Time);
	m_Time->SetPos(924,90);

	OMgr->Add(Player1);
	Player1->Translate(500, 700);
	OMgr->Add(Player1->m_HpUI);

	OMgr->Add(Player2);
	Player2->Translate(1400, 700);
	OMgr->Add(Player2->m_HpUI);


	OMgr->Add(Ball);
	OMgr->Add(Ball2);
	OMgr->Add(Ball3);
	OMgr->Add(Ball4);
	OMgr->Add(Ball5);
	OMgr->Add(Ball6);

	OMgr->Add(Player1Win);
	OMgr->Add(Player2Win);
}

void FightMgr::CollideTest()
{
	if(Player1->m_UseUpCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player1->m_UpCollision, Player2->m_Collision))
		{
			if(Player2->BackDashed == true)
				Player1->m_GetDoubleDamage = true;

			if (Player2->m_State != State::BLOCK && Player2->m_State != State::SIT && Player2->BackDashed != true)
				Player2->IsAttackedFromOther();

			if (Player2->m_State == State::SIT)
				Player1->m_GetDoubleDamage = true;
		}


	if (Player1->m_UseMidCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player1->m_MidCollision, Player2->m_Collision))
		{
			if (Player2->m_State != State::BLOCK)
				Player2->IsAttackedFromOther();
		}

	if (Player1->m_UseDownCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player1->m_DownCollision, Player2->m_Collision))
		{
			if (Player2->m_State != State::BLOCK && Player2->m_State != State::SIT)
				Player2->IsAttackedFromOther();
		}

	if (Player2->m_UseUpCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player2->m_UpCollision, Player1->m_Collision))
			{
			if (Player1->BackDashed == true)
				Player2->m_GetDoubleDamage = true;

				if (Player1->m_State != State::BLOCK && Player1->m_State != State::SIT && Player1->BackDashed != true)
					Player1->IsAttackedFromOther();

				if (Player1->m_State == State::SIT)
					Player2->m_GetDoubleDamage = true;
			}

	if (Player2->m_UseMidCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player2->m_MidCollision, Player1->m_Collision))
		{
			if (Player1->m_State != State::BLOCK)
				Player1->IsAttackedFromOther();
		}

	if (Player2->m_UseDownCollide)
		if (CollisionMgr::Get()->BoxCollideTest(Player2->m_DownCollision, Player1->m_Collision))
		{
			if (Player1->m_State != State::BLOCK && Player1->m_State != State::SIT)
				Player1->IsAttackedFromOther();
		}
}

bool FightMgr::Round()
{
	CollideTest();

	BackUI->m_Active = true;

	if (RoundStart == false)
	{
		if (m_Time->DelayTime == true)
		{
			Player1->m_DontMove = true;
			Player2->m_DontMove = true;
		}
		else
		{

			RoundStart = true;
			Player1->m_DontMove = false;
			Player2->m_DontMove = false;
		}
	}
	printf("MX : %f MY : %f\n", MX, MY);

	if (m_Time->Total <= 0)
	{
		if (Player1->m_Health > Player2->m_Health)
		{
			Player1WinCount++;
			RoundCount++;
			RoundEnd = true;
			End();
		}
		else if (Player2->m_Health > Player1->m_Health)
		{
			Player2WinCount++;
			RoundCount++;
			RoundEnd = true;
			End();
		}
		else
		{
			RoundCount++;
			RoundEnd = true;
			End();
		}
	}

	if (Player1->m_Health <= 0)
	{
		Player2WinCount++;
		RoundCount++;
		RoundEnd = true;
		End();
	}

	if (Player2->m_Health <= 0)
	{
		Player1WinCount++;
		RoundCount++;
		RoundEnd = true;
		End();
	}

	 // 플레이어 1윈 731 171 (2) 685 171(3)
	//1129 171 (1) 1176 171(2) 1224 171(3) 

	if (End() == true)
		return true;

	return false;
}

void FightMgr::EndRound()
{
	RoundStart = false;
	Set();
	m_Time->Init();

	Player1->HpInit();
	Player1->m_State = State::STAND;

	Player2->HpInit();
	Player2->m_State = State::STAND;
}

void FightMgr::Release()
{
}