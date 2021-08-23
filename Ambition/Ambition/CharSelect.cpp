#include "stdafx.h"
#include "CharSelect.h"


CharSelect::CharSelect(int mode)
{
	SelectCount = 0;
	Mode = mode;

	SteveButton = Sprite::Create("Resource/Button/Steve.png");
	NamIlButton = Sprite::Create("Resource/Button/NamIl.png");

	OMgr->Add(SteveButton);
	OMgr->Add(NamIlButton);

	SteveButton->SetPos(400, 300);
	NamIlButton->SetPos(1000, 300);
}


CharSelect::~CharSelect()
{
}

void CharSelect::Update(float deltaTime)
{
	if (SelectEnd == false)
	{
		switch (Mode)
		{
		case 1:
			AI = Character::NAMIL;

			//ĳ���� �ѹ��� ��
			if (CollisionMgr::Get()->BoxMouseTest(SteveButton->m_Collision))
			{
				if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
				{
					printf("aaaaa");
					Player1 = Character::STEVEFOX;
					OMgr->Remove(SteveButton);
					OMgr->Remove(NamIlButton);
					SelectEnd = true;
				}
			}
			else if (CollisionMgr::Get()->BoxMouseTest(NamIlButton->m_Collision))
			{
				if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
				{
					printf("aaaaa");
					Player1 = Character::NAMIL;
					OMgr->Remove(SteveButton);
					OMgr->Remove(NamIlButton);
					SelectEnd = true;
				}
			}

			break;

		case 2:
			if (SelectCount >= 2)
			{
				OMgr->Remove(SteveButton);
				OMgr->Remove(NamIlButton);
				SelectEnd = true;
			}
			//ĳ���� �ι� ��
			if (CollisionMgr::Get()->BoxMouseTest(SteveButton->m_Collision))
			{
				if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
				{
					if (SelectCount == 0)
						Player1 = Character::STEVEFOX;
					else if (SelectCount == 1)
						Player2 = Character::STEVEFOX;

					SelectCount++;
				}
			}

			else if (CollisionMgr::Get()->BoxMouseTest(NamIlButton->m_Collision))
			{
				if (IInput->GetKey(VK_LBUTTON) == KeyState::DOWN)
				{
					if (SelectCount == 0)
						Player1 = Character::NAMIL;
					else if (SelectCount == 1)
						Player2 = Character::NAMIL;
					
					SelectCount++;
					
				}
			}
			break;
		}

	}
	
}

void CharSelect::Render()
{
}
