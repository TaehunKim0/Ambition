#include "stdafx.h"
#include "Main.h"


Main::Main()
{
}


Main::~Main()
{
}

void Main::Init()
{
	m_Sp1 = Sprite::Create(L"Resource/1bo.png");
}

void Main::Update(float deltaTime)
{
	m_Sp1->Update(deltaTime);
}

void Main::Render()
{
	m_Sp1->Render();
}
