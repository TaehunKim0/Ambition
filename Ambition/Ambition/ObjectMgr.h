#pragma once
#define OMgr ObjectMgr::Get()

class ObjectMgr : public Singleton<ObjectMgr>
{
public:
	std::list<GameObject*> m_Objects;
	std::list<GameObject*> m_Collisions;

public:
	ObjectMgr();
	~ObjectMgr();

	void Add(GameObject* obj);
	void Remove(GameObject* obj);
	void RemoveCollision(GameObject* obj);

	void AddCollision(GameObject* obj);

	void Release();
	void Update(float deltaTime);
	void Render();

};