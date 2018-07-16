#pragma once
class Player : public FightObject
{
private:
	Animation * m_Punch;

public:
	Player();
	virtual ~Player();

public:
	void Update(float deltaTime);
	void Render();
};

