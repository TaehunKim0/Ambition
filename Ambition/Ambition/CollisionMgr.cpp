#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::BoxCollideTest(Collision* c1, Collision* c2)
{
	auto rect1 = c1->m_Rect;
	auto rect2 = c2->m_Rect;

	if (rect1.left < rect2.right && rect1.right > rect2.left)
	{
		if (rect1.top < rect2.bottom && rect1.bottom > rect2.top)
		{
			return true;
		}
	}

	return false;
}

bool CollisionMgr::BoxMouseTest(Collision* c)
{
	auto rect = c->m_Rect;

	if (rect.left <= MX && MX <= rect.right)
	{
		if (MY >= rect.top && MY <= rect.bottom)
		{
			return true;
		}
	}

	return false;
}
