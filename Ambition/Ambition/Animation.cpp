#include "stdafx.h"
#include "Animation.h"



Animation::Animation()
	: m_CurrentFrame(0)
	, m_Delay(0)
	, m_End(0)
	, m_LastFrame(0)
	, m_Middle(0)
	, m_Frame(0)
	, m_AutoPlay(1)
	, BAutoWhenEnd(0)
{
}


Animation::~Animation()
{
}

void Animation::AddFrame(std::string fileName)
{
	auto sprite = Sprite::Create(fileName);
	if (sprite)
	{
		m_Size = sprite->m_Size;
		m_Anim.push_back(sprite);
		sprite->m_Parent = this;
		m_LastFrame++;
	}
}

void Animation::AddContinueFrame(std::string fileName, int startFrame, int lastFrame)
{
	if(lastFrame > startFrame)
		for (int i = startFrame; i <= lastFrame; i++)
		{
			AddFrame(fileName + std::to_string(i) + ".png");
		}

	else if(lastFrame < startFrame)
		for (int i = startFrame; i >= lastFrame; i--)
		{
			AddFrame(fileName + std::to_string(i) + ".png");
		}
}

void Animation::Update(float deltaTime)
{
	if (BAutoWhenEnd && m_End)
		m_AutoPlay = false;

	if(m_AutoPlay)
		m_Frame++;

	if (m_Frame > m_Delay)
	{
		m_CurrentFrame++;
		m_Frame = 0;
	}

	if (m_LastFrame / 2 == m_CurrentFrame)
	{
		m_Middle = 1;
	}

	if (m_CurrentFrame >= m_LastFrame)
	{
		m_CurrentFrame = 0;
		m_End = 1;
	}

	m_Anim.at(m_CurrentFrame)->Update(deltaTime);
}

void Animation::Render()
{
	m_Anim.at(m_CurrentFrame)->Render();
}

void Animation::SetRed()
{
	for (int i = 0; i < m_Anim.size(); i++)
	{
		m_Anim.at(i)->SetRed();
	}
}
