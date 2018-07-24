#include "stdafx.h"
#include "ObjectManager.h"



ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Release()
{
	//������Ʈ ������
	for (auto iter = m_ObjectList.begin(); iter != m_ObjectList.end(); iter++)
	{
		delete (*iter);
	}
	m_ObjectList.clear();

	for (auto iter = m_CollisionList.begin(); iter != m_CollisionList.end(); iter++)
	{
		m_CollisionList.remove((*iter));
	}
	m_CollisionList.clear();
}

void ObjectManager::AddObject(GameObject * obj)
{
	if (obj)
		m_ObjectList.push_back(obj);
	else
		MessageBox(Application::GetInst()->m_Handle, L"������Ʈ �߰� ����", L"Error", MB_OK);
}

void ObjectManager::AddCollisionObject(GameObject * obj)
{
	if (obj)
		m_CollisionList.push_back(obj);
	else
		MessageBox(Application::GetInst()->m_Handle, L"�ݸ��� ������Ʈ �߰� ����", L"Error", MB_OK);
}

void ObjectManager::RemoveObject(GameObject * obj)
{
	obj->IsDestroyed = true;
}

void ObjectManager::RemoveCollisionObject(GameObject * obj)
{
	m_CollisionList.remove(obj);
}

void ObjectManager::Update(float deltaTime)
{
	for (auto iter = m_ObjectList.begin(); iter != m_ObjectList.end(); )
	{
		if ((*iter)->IsDestroyed == true)
		{
			GameObject* temp = (*iter);
			iter = m_ObjectList.erase(iter);
			m_CollisionList.remove(temp);
			delete temp;
		}
		else
			iter++;
	}

	for (auto iter = m_ObjectList.begin(); iter != m_ObjectList.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}

	for (auto iter = m_CollisionList.begin(); iter != m_CollisionList.end(); iter++)
	{
		
	}

}

void ObjectManager::Render()
{
	for (auto iter = m_ObjectList.begin(); iter != m_ObjectList.end(); iter++)
	{
		(*iter)->Render();
	}
}