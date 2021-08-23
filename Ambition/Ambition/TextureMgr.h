#pragma once
class TextureMgr : public Singleton<TextureMgr>
{
public:
	std::map<std::string, Texture*> m_Map;


public:
	TextureMgr();
	~TextureMgr();

	Texture* GetTexture(std::string fileName);

};

