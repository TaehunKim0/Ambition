#pragma once
class CharSelect : public GameObject
{
public:
	Sprite * SteveButton;
	Sprite* NamIlButton;

	int Mode;

	Character Player1;
	Character Player2;
	Character AI;

	bool SelectEnd;
	int SelectCount;

public:
	CharSelect(int mode);
	~CharSelect();

public:
	void Update(float deltaTime);
	void Render();
};

