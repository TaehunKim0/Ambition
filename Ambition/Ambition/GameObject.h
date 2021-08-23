#pragma once

enum class CollideTag
{
	UP,
	MID,
	DOWN,
	NONE
};



class Collision
{
public:
	RECT m_Rect;
	CollideTag m_Tag;

public:
	Collision() {
		SetRect(&m_Rect, 0, 0, 0, 0);
		m_Tag = CollideTag::NONE;
	}

	void Set(RECT rect, CollideTag tag)
	{
		m_Rect = rect; m_Tag = tag;
	}
};

// SetRect(&m_Collision, m_Position.x, m_Position.y, m_Position.x + m_Size.x, m_Position.y + m_Size.y);
class GameObject
{
public:
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Scale;
	D3DXVECTOR2 m_Size;
	
	Collision* m_Collision;

	float m_Rotation;

	bool m_UsePm;
	bool m_Destroyed;

public:
	GameObject* m_Parent;


public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Render();

	void SetCollision() {
		SetRect(&m_Collision->m_Rect, m_Position.x, m_Position.y, m_Position.x + m_Size.x, m_Position.y + m_Size.y);
	}

	D3DXMATRIX GetMatrix();

	void SetPos(float x, float y) {
		m_Position.x = x;
		m_Position.y = y;
	}
	void Translate(float x, float y)
	{
		m_Position.x += x;
		m_Position.y += y;
	}

};

