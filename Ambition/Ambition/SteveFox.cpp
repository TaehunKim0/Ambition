#include "stdafx.h"
#include "SteveFox.h"


SteveFox::SteveFox(PlayerType type, KEYTYPE key) : Fighter(type, key)
{
	m_Anim->AStand->AddContinueFrame("Resource/Steve/", 1, 6);
	m_Anim->AStand->Init(5, 1);

	m_Anim->APunch->AddContinueFrame("Resource/Steve/Punch/", 1, 7);
	m_Anim->APunch->Init(3, 1);

	m_Anim->AMoveLeft->AddContinueFrame("Resource/Steve/", 1, 6);
	m_Anim->AMoveLeft->Init(5, 1);

	m_Anim->AMoveRight->AddContinueFrame("Resource/Steve/", 1, 6);
	m_Anim->AMoveRight->Init(5, 1);

	m_Anim->ASit->AddContinueFrame("Resource/Steve/Sit/", 1, 5);
	m_Anim->ASit->Init(3, 1);
	m_Anim->ASit->BAutoWhenEnd = 1;

	m_Anim->ASitt->AddContinueFrame("Resource/Steve/Sit/", 6, 8);
	m_Anim->ASitt->Init(9, 1);

	if (type == PlayerType::Player1)
	{
		m_Scale = { -1.f,1.f };
		m_Position.x += 117.f;
	}

}

SteveFox::~SteveFox()
{
}

void SteveFox::Update(float deltaTime)
{
	if (IInput->GetKey('E') == KeyState::UP)
	{
		
	}

	if (m_Position.x - 100 < 0)
	{
		m_Position.x = 100;
	}

	if (m_Position.x > 1920 - 117)
	{
		m_Position.x = 1920 - 117;
	}

	if (m_Type == PlayerType::Player1)
	{
		SetRect(&m_Collision->m_Rect, m_Position.x - 117, m_Position.y, m_Position.x , m_Position.y + 306);

		
		//printf("m : %f\n", m_Position.x);

		auto left = m_Collision->m_Rect.left + 70;
		SetRect(&m_UpCollision->m_Rect, left, m_Position.y + 55, left + 40, m_Position.y + 95);
		SetRect(&m_MidCollision->m_Rect, left, m_Position.y + 95, left + 40, m_Position.y + 95 * 2);
		SetRect(&m_DownCollision->m_Rect, left, m_Position.y + 95 * 2, left + 40, m_Position.y + 95 * 3);

		Collider->m_Position = D3DXVECTOR2(m_Collision->m_Rect.left, m_Collision->m_Rect.top);
	}

	if (m_Type == PlayerType::AI || m_Type == PlayerType::Player2)
	{
		SetRect(&m_Collision->m_Rect, m_Position.x , m_Position.y, m_Position.x + 117, m_Position.y + 306);

		auto left = m_Collision->m_Rect.left + 7;

		SetRect(&m_UpCollision->m_Rect, left, m_Position.y + 55, left + 40, m_Position.y + 95);
		SetRect(&m_MidCollision->m_Rect, left, m_Position.y + 95, left + 40, m_Position.y + 95 * 2);
		SetRect(&m_DownCollision->m_Rect, left, m_Position.y + 95 * 2, left + 40, m_Position.y + 95 * 3);

		Collider->m_Position = D3DXVECTOR2(m_Collision->m_Rect.left, m_Collision->m_Rect.top);

	}

	Fighter::Update(deltaTime);
	//steve->Update(deltaTime);
}

void SteveFox::Render()
{
	Fighter::Render();
	//steve->Render();
}
