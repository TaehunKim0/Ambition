#include "stdafx.h"
#include "GamDok.h"


GamDok::GamDok()
{
}


GamDok::~GamDok()
{
}

void GamDok::Change(GameObject * scene)
{
	if (m_CurrentScene)
	{
		SAFE_DELETE(m_CurrentScene);
	}

	m_CurrentScene = scene;
}

void GamDok::Update(float deltaTime)
{
	IInput->Update();
	m_CurrentScene->Update(deltaTime);
	ObjectMgr::Get()->Update(deltaTime);
}

void GamDok::Render()
{
	m_CurrentScene->Render();
	ObjectMgr::Get()->Render();
}
