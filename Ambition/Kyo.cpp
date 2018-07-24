#include "stdafx.h"
#include "Kyo.h"


Kyo::Kyo()
{
	m_Anims->m_APunch->Init(1, 4, this);
	m_Anims->m_APunch->SetAnimEndWithFrame(1);
	m_Anims->m_APunch->AddContinueFrame(L"Resource/Kyo/Punch/", 1, 6);

	m_Anims->m_AKick->Init(1, 4, this);
	m_Anims->m_AKick->SetAnimEndWithFrame(1);
	m_Anims->m_AKick->AddContinueFrame(L"Resource/Kyo/Kick/", 1, 6);

	m_Anims->m_AStand->Init(1, 10, this);
	m_Anims->m_AStand->SetAnimEndWithFrame(0);
	m_Anims->m_AStand->AddContinueFrame(L"Resource/Kyo/Stand/", 1, 5);
	m_Anims->m_AStand->AddContinueFrame(L"Resource/Kyo/Stand/", 5, 1);

	m_Anims->m_ASit->Init(1, 2, this);
	m_Anims->m_ASit->SetAnimEndWithFrame(1);
	m_Anims->m_ASit->SetFrameZeroIsEnd(0);
	m_Anims->m_ASit->AddFrame(L"Resource/Kyo/Sit/1.png");
	m_Anims->m_ASit->AddFrame(L"Resource/Kyo/Sit/2.png");

	m_Anims->m_ALeft->Init(1, 8, this);
	m_Anims->m_ALeft->AddContinueFrame(L"Resource/Kyo/MoveLeft/", 1, 10);

	m_Anims->m_ARight->Init(1, 8, this);
	m_Anims->m_ARight->AddContinueFrame(L"Resource/Kyo/MoveLeft/", 1, 10);

	m_Anims->m_AJump->Init(1, 5, this);
	m_Anims->m_AJump->SetAnimEndWithFrame(1);
	m_Anims->m_AJump->AddContinueFrame(L"Resource/Kyo/Jump/", 1, 7);

	m_Anims->m_AJumpPunch->Init(1, 2, this);
	m_Anims->m_AJumpPunch->SetAnimEndWithFrame(1);
	m_Anims->m_AJumpPunch->AddContinueFrame(L"Resource/Kyo/JumpPunch/", 4, 10);

	m_PunchCombo = L"HHH";
	m_KickCombo = L"GGG";
	m_SpecialCombo = L"HGH";

}

Kyo::~Kyo()
{
}

void Kyo::Update(float deltaTime)
{
	Fighter::Update(deltaTime);
}

void Kyo::Render()
{
	Fighter::Render();
}
