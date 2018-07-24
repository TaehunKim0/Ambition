#include "stdafx.h"
#include "Terry.h"


Terry::Terry()
{
	m_Anims->m_APunch->Init(1, 4, this);
	m_Anims->m_APunch->SetAnimEndWithFrame(1);
	m_Anims->m_APunch->AddContinueFrame(L"Resource/Terry/Punch/", 1, 6);

	m_Anims->m_AKick->Init(1, 4, this);
	m_Anims->m_AKick->SetAnimEndWithFrame(1);
	m_Anims->m_AKick->AddContinueFrame(L"Resource/Terry/Kick/", 1, 6);

	m_Anims->m_AStand->Init(1, 10, this);
	m_Anims->m_AStand->SetAnimEndWithFrame(0);
	m_Anims->m_AStand->AddContinueFrame(L"Resource/Terry/Stand/", 1, 5);
	m_Anims->m_AStand->AddContinueFrame(L"Resource/Terry/Stand/", 5, 1);

	m_Anims->m_ASit->Init(1, 2, this);
	m_Anims->m_ASit->SetAnimEndWithFrame(1);
	m_Anims->m_ASit->SetFrameZeroIsEnd(0);
	m_Anims->m_ASit->AddFrame(L"Resource/Terry/Sit/1.png");
	m_Anims->m_ASit->AddFrame(L"Resource/Terry/Sit/2.png");

	m_Anims->m_ALeft->Init(1, 8, this);
	m_Anims->m_ALeft->AddContinueFrame(L"Resource/Terry/MoveLeft/", 1, 10);

	m_Anims->m_ARight->Init(1, 8, this);
	m_Anims->m_ARight->AddContinueFrame(L"Resource/Terry/MoveLeft/", 1, 10);

	m_Anims->m_AJump->Init(1, 5, this);
	m_Anims->m_AJump->SetAnimEndWithFrame(1);
	m_Anims->m_AJump->AddContinueFrame(L"Resource/Terry/Jump/", 1, 7);

	m_Anims->m_AJumpPunch->Init(1, 2, this);
	m_Anims->m_AJumpPunch->SetAnimEndWithFrame(1);
	m_Anims->m_AJumpPunch->AddContinueFrame(L"Resource/Terry/JumpPunch/", 4, 10);
}


Terry::~Terry()
{
}

void Terry::Update(float deltaTime)
{
}

void Terry::Render()
{
}
