#pragma once
class STutorial : public GameObject
{
public:
	Fighter * Player;
	Fighter * AI;
	Sprite* Wall;
	Character PlayerCharacter;

	CharSelect *SelectChar;
	FightMgr* FMgr;
	bool ModeSelected;
	bool CharacterSelected;

public:
	STutorial();
	~STutorial();

	void SelectCharacter();


	void Update(float deltaTime);
	void Render();

};

