#pragma once
class Sprite : public GameObject
{
public:
	Texture * m_Texture;


private:
	Sprite();
	~Sprite();

	bool Init(wstring fileName);
public:
	static Sprite* Create(wstring fileName);
	
public:
	void Update(float deltaTime) override;
	void Render() override;

};

