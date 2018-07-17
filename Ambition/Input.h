#pragma once

#define InputSystem Input::GetInst()

enum class KeyState
{
	DOWN,
	UP,
	PRESS,
	NONE
};

class Input : public Singleton<Input>
{
private:
	int m_iCurrentState[255];
	int m_iPrevState[255];

	bool m_bCurrentState;
	bool m_bPrevState;

	D3DXVECTOR2 m_vMousePos;

public:
	Input();
	~Input();

public:
	void Update();

private:
	void KeyUpdate();
	void MouseUpdate();

public:
	KeyState GetKey(int key);
};