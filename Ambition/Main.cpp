#include "stdafx.h"
#include "Main.h"
#include"InDoorStadium.h"
#include"SelectCharacter.h"


Main::Main()
{
}


Main::~Main()
{
	ObjectManager::GetInst()->Release();
}

void Main::Init()
{
	m_BackGround = Sprite::Create(L"Resource/Back.png");
	m_FightButton = Sprite::Create(L"Resource/Fight.png");

	ObjectManager::GetInst()->AddObject(m_BackGround);
	ObjectManager::GetInst()->AddObject(m_FightButton);

	m_FightButton->SetPosition(604, 411);
}

void Main::Update(float deltaTime)
{
	printf("%f %f \n", InputSystem->GetMousePos().x, InputSystem->GetMousePos().y);

	if (CollisionMgr::GetInst()->BoxMouseCollideTest(m_FightButton->m_CollisionRect))
	{
		if(InputSystem->GetKey(VK_LBUTTON) == KeyState::DOWN)
			SceneDirector::GetInst()->ChangeScene(new SelectCharacter());
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneDirector::GetInst()->ChangeScene(new InDoorStadium());
	}
}

void Main::Render()
{
}
