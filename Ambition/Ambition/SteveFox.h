#pragma once
class SteveFox : public Fighter
{
private:
	Sprite * steve;
public:
	SteveFox(PlayerType type, KEYTYPE key);
	~SteveFox();

	void Update(float deltaTime);
	void Render();
};