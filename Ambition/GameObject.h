#pragma once
class GameObject
{
public:
	D3DXMATRIX m_mMatrix;
	D3DXVECTOR2 m_vPosition;
	D3DXVECTOR2 m_vScale;
	D3DXVECTOR2 m_vSize;


	float m_fRotation;

	wstring m_wName;

	bool m_bVisible;
	bool m_bUsePm;

public:
	GameObject * m_Parent;

public:
	GameObject();
	~GameObject();

public:
	virtual void Update(float deltaTime);
	virtual void Render();

	D3DXMATRIX GetMatrix();

};