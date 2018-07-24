#pragma once

enum class CharacterType
{
	KYO,
	TERRY,
	NONE
};

class Player;
class InDoorStadium : public GameObject
{
public:
	Player* player;
	Sprite* BackGround;
	Sprite* Life;

	CharacterType PlayerType;

	Fighter* p;

public:
	InDoorStadium();
	~InDoorStadium();

	void SetPlayerCharacter(CharacterType type)
	{
		PlayerType = type;
	}

	void Init();

	void Update(float deltaTime);
	void Render();
};