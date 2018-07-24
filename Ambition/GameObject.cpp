#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
	: m_vPosition(0.f,0.f)
	, m_vScale(1.f,1.f)
	, m_fRotation(0.f)
	, m_wName(L"")
	, m_bVisible(1)
	, m_bUsePm(1)
	, m_Parent(NULL)
	, m_vSize(0.f,0.f)
{
	D3DXMatrixIdentity(&m_mMatrix);
	SetRect(&m_CollisionRect, 0, 0, 0, 0);
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
	D3DXMatrixTransformation2D(&m, NULL, NULL, &m_vScale, NULL, m_fRotation, &m_vPosition);

	if (m_bUsePm)
	{
		if (m_Parent)
			m *= m_Parent->GetMatrix();
	}

	return m;
}

void GameObject::SetParent(GameObject * parent)
{
	m_Parent = parent;
}

void GameObject::Translate(float x, float y)
{
	m_vPosition.x += x;
	m_vPosition.y += y;
}

void GameObject::SetPosition(float x, float y)
{
	m_vPosition.x = x;
	m_vPosition.y = y;
}

void GameObject::SetScale(float x, float y)
{
	m_vScale.x = x;
	m_vScale.y = y;
}
