#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::CreateTextureFromFile(std::string fileName)
{
	D3DXCreateTextureFromFileEx(App::Get()->m_Dev, fileName.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &m_Texture);

	if (m_Texture == nullptr)
		return false;

	D3DSURFACE_DESC desc;
	m_Texture->GetLevelDesc(0, &desc);

	m_Size.x = (float)(desc.Width);
	m_Size.y = (float)(desc.Height);

	return true;
}
