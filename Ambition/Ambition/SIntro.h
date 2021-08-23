#pragma once
class SIntro : public GameObject
{
private:
	Animation * Intro;


public:
	SIntro();
	~SIntro();

	void Update(float deltaTime);
	void Render();
};

