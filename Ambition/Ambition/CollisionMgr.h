#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	CollisionMgr();
	~CollisionMgr();

	bool BoxCollideTest(Collision* c1, Collision* c2);
	bool BoxMouseTest(Collision* c);

};

