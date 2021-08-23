#include "stdafx.h"
#include "SIntro.h"
#include"SMain.h"

SIntro::SIntro()
{
	Intro = new Animation();
	Intro->AddContinueFrame("Resource/Intro/", 1, 3);
	Intro->Init(10, 1);
	OMgr->Add(Intro);
}


SIntro::~SIntro()
{
}

void SIntro::Update(float deltaTime)
{
	if (Intro->m_End)
		GamDok::Get()->Change(new SMain());
}

void SIntro::Render()
{
}
