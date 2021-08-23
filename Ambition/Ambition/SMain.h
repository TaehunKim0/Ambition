#pragma once
class SMain : public GameObject
{
public:
	Sprite * BackGround;

	Sprite* Tutorial;
	Sprite* GameStart;
	Sprite* Option;
	Sprite* GameEnd;

public:
	SMain();
	~SMain();

	void Update(float deltaTime);
	void Render();

};

