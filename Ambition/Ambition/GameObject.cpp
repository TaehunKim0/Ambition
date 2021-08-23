#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
	: m_Destroyed(0)
	, m_Parent(NULL)
	, m_Position(0.f,0.f)
	, m_Scale(1.f,1.f)
	, m_Rotation(0.f)
	, m_Size(0.f,0.f)
	, m_UsePm(1)
{
	m_Collision = new Collision();
}


GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
	
}

void GameObject::Render()
{
}

D3DXMATRIX GameObject::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, NULL, NULL, &m_Scale, NULL, m_Rotation, &m_Position);

	if(m_UsePm)
		if (m_Parent)
		{
			m *= m_Parent->GetMatrix();
		}

	return m;
}
