#pragma once
class Texture
{
public:
	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR2 m_vSize;

public:
	Texture();
	~Texture();

	bool InitTextureFromFile(wstring fileName);
};

