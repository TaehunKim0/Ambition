#pragma once
class Main : public GameObject
{
public:
	Sprite * m_Sp1;

public:
	Main();
	~Main();

public:
	void Init();

	void Update(float deltaTime);
	void Render();
};

