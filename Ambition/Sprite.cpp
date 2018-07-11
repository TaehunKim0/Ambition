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
}
