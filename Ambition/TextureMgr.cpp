#include "stdafx.h"
#include "TextureMgr.h"


TextureMgr::TextureMgr()
{
}


TextureMgr::~TextureMgr()
{
}

Texture* TextureMgr::CreateTexture(wstring fileName)
{
	if (!(m_TextureMap.count(fileName)))
	{
		auto texture = new (std::nothrow) Texture();
		if (texture && texture->InitTextureFromFile(fileName))
		{
			m_TextureMap[fileName] = texture;
		}
		else
		{
			SAFE_DELETE(texture);
			return nullptr;
		}
	}

	return m_TextureMap[fileName];

}
