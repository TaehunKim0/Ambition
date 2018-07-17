#include"stdafx.h"
#include "Input.h"

Input::Input()
{
	ZeroMemory(&m_iCurrentState, sizeof(m_iCurrentState));
	ZeroMemory(&m_iPrevState, sizeof(m_iPrevState));

	m_vMousePos = D3DXVECTOR2(0.f, 0.f);

	m_bCurrentState = FALSE;
	m_bPrevState = FALSE;
}


Input::~Input()
{
}

void Input::Update()
{
	KeyUpdate();
	MouseUpdate();
}

void Input::KeyUpdate()
{
	for (int i = 0; i < 255; i++)
	{
		m_iPrevState[i] = m_iCurrentState[i];
		m_iCurrentState[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

void Input::MouseUpdate()
{
	POINT position;
	GetCursorPos(&position);

	ScreenToClient(Application::GetInst()->m_Handle, &position);

	m_vMousePos.x = static_cast<float>(position.x);
	m_vMousePos.y = static_cast<float>(position.y);
}

KeyState Input::GetKey(int key)
{
	m_bPrevState = m_iPrevState[key];
	m_bCurrentState = m_iCurrentState[key];

	if (m_bPrevState == true && m_bCurrentState == true)
		return KeyState::PRESS;

	else if (m_bPrevState == true && m_bCurrentState == false)
		return KeyState::UP;

	else if (m_bPrevState == false && m_bCurrentState == true)
		return KeyState::DOWN;

	return KeyState::NONE;
}
