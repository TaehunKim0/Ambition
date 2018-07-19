#pragma once

class Player;
class InDoorStadium : public GameObject
{
public:
	Player* player;
	Sprite* BackGround;
	Sprite* Life;
public:
	InDoorStadium();
	~InDoorStadium();

	void Update(float deltaTime);
	void Render();
};