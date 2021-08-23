#pragma once
class Sprite : public GameObject
{
public:
	Texture * m_Texture;
	D3DXVECTOR2 DeltaDrawSize;
	D3DXVECTOR2 DeltaDrawPosition;

	bool m_Active;
	int A;
	int R;
	int G;
	int B;

	bool Red;

public:
	Sprite();
	virtual ~Sprite();

	static Sprite* Create(std::string fileName);
	bool Init(std::string fileName);

	int RedCount;

	void SetRed() {
		Red = true;
		G = 0;
		B = 0;
	}

	void Update(float deltaTime);
	void Render();
};

