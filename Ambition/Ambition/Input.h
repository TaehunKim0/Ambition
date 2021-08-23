#pragma once

enum class KeyState
{
	DOWN,
	UP,
	PRESS,
	NONE
};

#define IInput Input::Get()
#define MX Input::Get()->m_MousePos.x
#define MY Input::Get()->m_MousePos.y

class Input : public Singleton<Input>
{
public:
	int m_Current[255];
	int m_Prev[255];

	bool m_bCurrent;
	bool m_bPrev;

	D3DXVECTOR2 m_MousePos;

public:
	Input();
	~Input();

	void Update();
	KeyState GetKey(int key);
	
};

