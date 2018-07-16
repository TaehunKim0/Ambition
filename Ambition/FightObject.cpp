#include "stdafx.h"
#include "FightObject.h"


FightObject::FightObject() :
	m_bCanMove(1)
	, m_State(State::NONE)
{
}


FightObject::~FightObject()
{
}

void FightObject::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void FightObject::Render()
{
	GameObject::Render();

}

void FightObject::Move()
{
}
