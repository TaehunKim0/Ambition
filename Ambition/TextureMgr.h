#pragma once
class TextureMgr : public Singleton<TextureMgr>
{
public:
	map<wstring, Texture*> m_TextureMap;

public:
	TextureMgr();
	~TextureMgr();

public:
	Texture * CreateTexture(wstring fileName);
};