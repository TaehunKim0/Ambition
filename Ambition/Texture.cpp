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
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx
	(Renderer::GetInst()->GetDevice(), fileName.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED
		, D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &m_pTexture);

	if FAILED(hr)
	{
		MessageBox(nullptr, L"텍스쳐 생성 실패", L"Arror", MB_OK);
		return false;
	}

	D3DSURFACE_DESC desc;
	m_pTexture->GetLevelDesc(0, &desc);

	m_vSize.x = (float)(desc.Width);
	m_vSize.y = (float)(desc.Height);

	return true;
}