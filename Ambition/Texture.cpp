#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::InitTextureFromFile(wstring fileName)
{
	if FAILED(D3DXCreateTextureFromFile(Renderer::GetInst()->GetDevice(), fileName.c_str(), &m_pTexture))
	{
		MessageBox(nullptr, L"텍스쳐 생성 실패", L"Arror", MB_OK);
		return false;
	}

	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(fileName.c_str(), &info);
	m_vSize.x = (float)(info.Width);
	m_vSize.y = (float)(info.Height);

	return true;
}