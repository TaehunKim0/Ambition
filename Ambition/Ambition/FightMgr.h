#pragma once
class FightMgr
{
public:
	int time;

	bool RoundStart;

	Fighter * Player1;
	Fighter * Player2;

	Sprite* Player1Win;
	Sprite* Player2Win;


	Sprite* Ball6;
	Sprite* Ball5;
	Sprite* Ball4;
	Sprite* Ball3;
	Sprite* Ball2;
	Sprite* Ball;

	Sprite* BackUI;
	TimeUI* m_Time;

	int Player1WinCount;
	int Player2WinCount;


	int RoundCount;
	bool RoundEnd;

	void EndRound();

	bool End() {
		
		switch (Player1WinCount)
		{
		case 1:
			Ball->SetPos(837, 158);
			Ball->m_Active = true;
			break;

		case 2:
			Ball2->SetPos(806, 158);
			Ball2->m_Active = true;
			break;

		case 3:
			Ball3->SetPos(774, 158);
			Ball3->m_Active = true;
			break;
		}

		switch (Player2WinCount)
		{
		case 1:
			Ball4->SetPos(1070, 158);
			Ball4->m_Active = true;
			break;

		case 2:
			Ball5->SetPos(1102, 158);
			Ball5->m_Active = true;
			break;

		case 3:
			Ball6->SetPos(1133, 158);
			Ball6->m_Active = true;
			break;
		}


		if (Player1WinCount >= 3)
		{
			printf("플레이어 1 윈!\n");
		}
		else if (Player2WinCount >= 3)
		{
			printf("플레이어 2 윈!\n");
		}

		if (RoundEnd)
		{
			return true;
		}
	}

	void Release();
	void Set()
	{
		Player1->m_Health = 100;
		Player2->m_Health = 100;

		Player1->SetPos(610, 700);
		Player2->SetPos(1400, 700);
		BackUI->m_Active = false;
		RoundEnd = false;
	}

public:
	FightMgr();
	~FightMgr();

	void CreateCharacter(Character p1, Character p2 , bool ai);
	void CollideTest();

	bool Round();


};