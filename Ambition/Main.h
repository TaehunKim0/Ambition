#pragma once
class Main : public GameObject
{
public:
	Sprite * m_BackGround;
	Sprite * m_FightButton;

	std::queue<char> Buf;


public:
	Main();
	~Main();

public:
	void Init();

	void Update(float deltaTime);
	void Render();
};