#include "stdafx.h"
#include "TimeUI.h"


TimeUI::TimeUI()
{
	ATen = new Animation();
	ATen->m_Parent = this;
	AOne = new Animation();
	AOne->m_Parent = this;

	Delay = new Animation();
	Delay->m_Parent = this;

	ATen->SetPos(-10, 0);
	Delay->SetPos(20, 0);
	AOne->SetPos(50, 0);

	Total = 90;
	One = 0;
	Ten = 0;
	Frame = 0;
	DelayTime = true;
	Delays = false;
}


TimeUI::~TimeUI()
{
}

void TimeUI::Init()
{
	Total = 90;
	One = 0;
	Ten = 0;
	Frame = 0;
	DelayTime = true;
	Delays = false;
}

void TimeUI::Calc()
{
	ATen->m_CurrentFrame = Total / 10;
	AOne->m_CurrentFrame = Total % 10;
}

void TimeUI::SetAnim()
{
	ATen->Init(0, 0);
	ATen->AddContinueFrame("Resource/Time/", 0, 9);

	AOne->Init(0, 0);
	AOne->AddContinueFrame("Resource/Time/", 0, 9);

	Delay->Init(0, 0);
	Delay->AddContinueFrame("Resource/Time/", 3, 1);

	Delay->m_CurrentFrame = 3;
	ATen->m_CurrentFrame = 9;
	AOne->m_CurrentFrame = 0;
}

void TimeUI::Update(float deltaTime)
{
	Calc();

	if(DelayTime)
	{
		if(Delays == false)
			Delay->Update(deltaTime);

		Frame++;
		if (Frame > 60)
		{
			Frame = 0;
			Delay->m_CurrentFrame += 1;
		}

		if (Delay->m_CurrentFrame >= 3)
		{
			DelayTime = false;
			Frame = 0;
			Delays = true;
		}
	}
	else
	{
		Frame++;
		if (Frame > 60)
		{
			Total--;
			Frame = 0;
		}

		ATen->Update(deltaTime);
		AOne->Update(deltaTime);
	}
}

void TimeUI::Render()
{
	if (!DelayTime)
	{
		ATen->Render();
		AOne->Render();
	}
	else
	{
		if(Delays == false)
			Delay->Render();
	}
}