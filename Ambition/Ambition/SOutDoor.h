#pragma once
class SOutDoor : public GameObject
{
public:
	Sprite * BackGround;

	Sprite* Button1p;
	Sprite* Button2p;
	Sprite* AIButton;

	bool Count;
	int Mode;

	bool ModeSelected;
	bool CharacterSelected;

	Sprite* Health1P;
	Sprite* Health2P;

	Sprite* Out;

	int frame;

	Sprite* GameOver;

	bool Stop;

	CharSelect* SelectChar;
	FightMgr* FMgr;

	bool Round1End;
	bool Round2End;
	bool Round3End;
public:
	SOutDoor();
	~SOutDoor();

	bool SelectMode();
	bool SelectCharacter();

	void Update(float deltaTime);
	void Render();
};

