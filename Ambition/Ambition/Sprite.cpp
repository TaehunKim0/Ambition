#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
	RedCount = 0;
	A = 255;
	R = 255;
	G = 255;
	B = 255;

	m_Active = true;
	DeltaDrawSize = { 0.f,0.f };
	DeltaDrawPosition = { 0.f,0.f };
}


Sprite::~Sprite()
{
}

Sprite * Sprite::Create(std::string fileName)
{
	auto sprite = new(std::nothrow) Sprite();
	if (sprite && sprite->Init(fileName))
	{
		return sprite;
	}

	SAFE_DELETE(sprite);
	return nullptr;
}

bool Sprite::Init(std::string fileName)
{
	m_Texture = TextureMgr::Get()->GetTexture(fileName);
	if (m_Texture)
		m_Size = m_Texture->m_Size;
	else
		return false;

	SetRect(&m_Collision->m_Rect, m_Position.x, m_Position.y, m_Position.x + m_Size.x, m_Position.y + m_Size.y);

	return true;
}

void Sprite::Update(float deltaTime)
{
}

void Sprite::Render()
{
	if (!m_Active)
		return;

	auto sprite = App::Get()->m_Sprite;

	RECT srcRect;
	if (DeltaDrawSize.x != 0)
	{
		printf("");
	}

	SetRect(&srcRect, DeltaDrawPosition.x, DeltaDrawPosition.y, m_Size.x + DeltaDrawSize.x, m_Size.y + DeltaDrawSize.y);

	SetRect(&m_Collision->m_Rect, m_Position.x, m_Position.y, m_Position.x + m_Size.x, m_Position.y + m_Size.y);

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&GetMatrix());

	if (Red == false)
	{
		sprite->Draw(m_Texture->m_Texture, &srcRect, NULL, NULL, D3DCOLOR_ARGB(A, R, G, B));
	}
	else
	{
		sprite->Draw(m_Texture->m_Texture, &srcRect, NULL, NULL, D3DCOLOR_ARGB(A, R, G, B));
		RedCount++;

		if (RedCount == 60)
		{
			RedCount = 0;
			Red = false;
		}
	}

	sprite->End();

}
