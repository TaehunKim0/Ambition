#pragma once
class Kyo : public Fighter
{
public:
	Kyo();
	virtual ~Kyo();

	void Update(float deltaTime);
	void Render();
};