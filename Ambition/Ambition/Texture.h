#pragma once
class Texture
{
public:
	LPDIRECT3DTEXTURE9 m_Texture;
	D3DXVECTOR2 m_Size;

public:
	Texture();
	~Texture();

	bool CreateTextureFromFile(std::string fileName);

};

