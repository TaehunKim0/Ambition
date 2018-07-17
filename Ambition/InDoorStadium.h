#pragma once

class Player;
class InDoorStadium : public GameObject
{
public:
	Player* player;

public:
	InDoorStadium();
	~InDoorStadium();

	void Update(float deltaTime);
	void Render();
};

