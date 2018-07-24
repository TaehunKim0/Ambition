#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::BoxCollideTest(RECT rect1, RECT rect2)
{
	if (rect1.left < rect2.right && rect1.right > rect2.left)
	{
		if (rect1.top < rect2.bottom && rect1.bottom > rect2.top)
		{
			return true;
		}
	}

	return false;
}

bool CollisionMgr::BoxMouseCollideTest(RECT rect)
{
	D3DXVECTOR2 MousePos = InputSystem->GetMousePos();

	if (rect.left <= MousePos.x && MousePos.x <= rect.right)
	{
		if (rect.top <= MousePos.y && MousePos.y <= rect.bottom)
			return true;
	}

	return false;
}
