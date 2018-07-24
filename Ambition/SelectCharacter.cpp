#include "stdafx.h"
#include "SelectCharacter.h"
#include"InDoorStadium.h"

SelectCharacter::SelectCharacter()
{
	Back = Sprite::Create(L"Resource/Select.png");
	KyoButton = Sprite::Create(L"Resource/KyoButton.png");
	TerryButton = Sprite::Create(L"Resource/TerryButton.png");

	ObjectManager::GetInst()->AddObject(Back);
	ObjectManager::GetInst()->AddObject(KyoButton);
	ObjectManager::GetInst()->AddObject(TerryButton);
	KyoButton->SetPosition(361, 297);
	TerryButton->SetPosition(1111, 297);
}


SelectCharacter::~SelectCharacter()
{
}

void SelectCharacter::Update(float deltaTime)
{
	printf("%f %f \n", InputSystem->GetMousePos().x, InputSystem->GetMousePos().y);

	if (CollisionMgr::GetInst()->BoxMouseCollideTest(KyoButton->m_CollisionRect))
	{
		if (InputSystem->GetKey(VK_LBUTTON) == KeyState::DOWN)
		{
			InDoorStadium* stadium = new InDoorStadium();
			stadium->SetPlayerCharacter(CharacterType::KYO);
			stadium->Init();
			SceneDirector::GetInst()->ChangeScene(stadium);
		}

	}


}

void SelectCharacter::Render()
{
}
