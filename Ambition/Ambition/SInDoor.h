#pragma once
class SInDoor : public GameObject
{
public:
	Sprite * BackGround;

	Sprite* Button1p;
	Sprite* Button2p;
	Sprite* AIButton;
	
	Sprite* In;

	bool Stop;

	bool Count;
	int Mode;

	bool ModeSelected;
	bool CharacterSelected;

	Sprite* Health1P;
	Sprite* Health2P;

	CharSelect* SelectChar;
	FightMgr* FMgr;

	int frame;


	bool Round1End;
	bool Round2End;
	bool Round3End;

public:
	SInDoor();
	~SInDoor();

	bool SelectMode();
	bool SelectCharacter();

	void Update(float deltaTime);
	void Render();
};