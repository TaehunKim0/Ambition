#include "stdafx.h"
#include "ObjectMgr.h"


ObjectMgr::ObjectMgr()
{
}


ObjectMgr::~ObjectMgr()
{
}

void ObjectMgr::Add(GameObject * obj)
{
	if (obj)
	{
		m_Objects.push_back(obj);
	}
}

void ObjectMgr::Remove(GameObject * obj)
{
	obj->m_Destroyed = 1;
}

void ObjectMgr::RemoveCollision(GameObject * obj)
{
	m_Collisions.remove(obj);
}


void ObjectMgr::AddCollision(GameObject * obj)
{
	if (obj)
	{
		m_Collisions.push_back(obj);
	}
}

void ObjectMgr::Release()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_Objects.clear();

	for (auto iter = m_Collisions.begin(); iter != m_Collisions.end(); iter++)
	{
		m_Collisions.remove(*iter);
	}
	m_Collisions.clear();
}

void ObjectMgr::Update(float deltaTime)
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->m_Destroyed)
		{
			GameObject* temp = (*iter);
			iter = m_Objects.erase(iter);
			SAFE_DELETE(temp);
		}
		else
		{
			iter++;
		}

	}

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}
}

void ObjectMgr::Render()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		(*iter)->Render();
	}
}
