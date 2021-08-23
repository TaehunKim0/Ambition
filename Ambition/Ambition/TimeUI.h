#pragma once
class TimeUI : public GameObject
{
public:
	Animation * ATen;
	Animation * AOne;
	Animation * Delay;

	bool DelayTime;

	int Total;

	int Ten;
	int One;

	int Frame;

	bool Delays;

public:
	TimeUI();
	~TimeUI();


	void Init();

	void Calc();
	void SetAnim();

	void Update(float deltaTime);
	void Render();
};

