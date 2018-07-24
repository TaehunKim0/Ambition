#pragma once
class SelectCharacter : public GameObject
{
private:
	Sprite * Back;
	Sprite * KyoButton;
	Sprite * TerryButton;

public:
	SelectCharacter();
	~SelectCharacter();

	void Update(float deltaTime);
	void Render();

};

