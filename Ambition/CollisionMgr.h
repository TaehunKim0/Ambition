#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	CollisionMgr();
	~CollisionMgr();

	bool BoxCollideTest(RECT rect1, RECT rect2);
	bool BoxMouseCollideTest(RECT rect);

};

