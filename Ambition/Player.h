#pragma once
class Player : public FightObject
{
private:


public:
	Player();
	virtual ~Player();

public:
	void Update(float deltaTime);
	void Render();

public:
	virtual void Punch();
	virtual void Kick();
	virtual void Sit();
	virtual void Block();
	virtual void Jump();

	void Move();
};

