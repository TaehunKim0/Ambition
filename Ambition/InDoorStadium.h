#pragma once

class Player;
class InDoorStadium : public GameObject
{
public:
	Player* player;
	Sprite* BackGround;

public:
	InDoorStadium();
	~InDoorStadium();

	void Update(float deltaTime);
	void Render();
};

