#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
	CMgr = new CommandMgr();
}


Controller::~Controller()
{
}

void Controller::RunAI()
{
	if (m_AIPattern.size() < 3)
		AddPattern();
}

State Controller::GetPattern()
{
	State P = m_AIPattern.front();
	m_AIPattern.pop();
	return P;
}

void Controller::AddPattern()
{
	int a = rand() % 5;
	switch (a)
	{
	case 0:
		m_AIPattern.push(State::MOVE);
		break;

	case 1:
		m_AIPattern.push(State::PUNCH);
		break;

	case 2:
		m_AIPattern.push(State::KICK);
		break;

	case 3:
		m_AIPattern.push(State::BLOCK);
		break;

	case 4:
		m_AIPattern.push(State::SIT);
		break;

	case 5:
		m_AIPattern.push(State::STAND);
		break;
	}


}
