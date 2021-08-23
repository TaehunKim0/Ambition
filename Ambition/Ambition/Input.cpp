#include "stdafx.h"
#include "Input.h"


Input::Input()
{
	ZeroMemory(&m_Current, sizeof(m_Current));
	ZeroMemory(&m_Prev, sizeof(m_Prev));

	m_MousePos = { 0.f,0.f };
}


Input::~Input()
{
}

void Input::Update()
{
	for (int i = 0; i < 255; i++)
	{
		m_Prev[i] = m_Current[i];
		m_Current[i] = static_cast<bool>(GetAsyncKeyState(i));
	}

	POINT p;
	GetCursorPos(&p);
	ScreenToClient(App::Get()->m_Handle, &p);

	m_MousePos.x = (float)(p.x);
	m_MousePos.y = (float)(p.y);
}

KeyState Input::GetKey(int key)
{
	m_bCurrent = m_Current[key];
	m_bPrev = m_Prev[key];

	if (m_bPrev == true && m_bCurrent == true)
		return KeyState::PRESS;

	if (m_bPrev == true && m_bCurrent == false)
		return KeyState::UP;

	if (m_bPrev == false && m_bCurrent == true)
		return KeyState::DOWN;


	return KeyState::NONE;
}
