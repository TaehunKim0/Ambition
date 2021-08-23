#include "stdafx.h"
#include "TextureMgr.h"


TextureMgr::TextureMgr()
{
}


TextureMgr::~TextureMgr()
{
}

Texture * TextureMgr::GetTexture(std::string fileName)
{
	if (!m_Map.count(fileName))
	{
		auto texture = new(std::nothrow)Texture();
		if (texture && texture->CreateTextureFromFile(fileName))
		{
			m_Map[fileName] = texture;
		}
		else
		{
			SAFE_DELETE(texture);
			return nullptr;
		}
	}

	return m_Map[fileName];
}
