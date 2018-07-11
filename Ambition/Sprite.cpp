#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

bool Sprite::Init(wstring fileName)
{
	m_Texture = TextureMgr::GetInst()->CreateTexture(fileName);
	if (m_Texture == nullptr)
		return false;

	m_vSize = m_Texture->m_vSize;

	return true;
}

Sprite * Sprite::Create(wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if(sprite && sprite->Init(fileName))
	{
		return sprite;
	}

	SAFE_DELETE(sprite);
	return nullptr;
}

void Sprite::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Sprite::Render()
{
	GameObject::Render();

	auto sprite = Renderer::GetInst()->m_Sprite;

	RECT rect;
	SetRect(&rect, 0, 0, m_vSize.x, m_vSize.y);

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&GetMatrix());
	sprite->Draw(m_Texture->m_pTexture, &rect , NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	sprite->End();
}
