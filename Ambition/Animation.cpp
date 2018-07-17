#include"stdafx.h"
#include "Animation.h"
Animation::Animation()
	: m_iCurrentFrame(0)
	, m_iFrame(0)
	, m_iDelay(0)
	, m_iLastFrame(0)
	, m_bEnd(0)
	, m_bPlay(1)
	, m_bAutoPlay(0)
	, m_bEndWithFrame(0)
{
}

Animation::~Animation()
{
}

void Animation::Init(bool autoplay, int delay)
{
	m_bAutoPlay = autoplay;
	m_iDelay = delay;
}

void Animation::Set()
{
	m_bEnd = false;
	m_bEndWithFrame = false;
}

void Animation::SetCurrentFrame(int frame)
{
	m_iCurrentFrame = frame;
}

void Animation::SetAutoPlay(bool play)
{
	m_bAutoPlay = play;
}

void Animation::SetAnimEndWithFrame(bool end)
{
	m_bEndWithFrame = end;
}

void Animation::AddFrame(wstring fileName)
{
	auto sprite = Sprite::Create(fileName);

	if (sprite)
		m_Anim.push_back(sprite);

	m_iLastFrame++;

}

void Animation::AddContinueFrame(wstring fileName, int firstFrame, int lastFrame)
{
	for (int i = firstFrame; i <= lastFrame; i++)
	{
		auto sprite = Sprite::Create(fileName.c_str() + to_wstring(i) + L".png");

		if(sprite)
			m_Anim.push_back(sprite);

		m_iLastFrame++;
	}
}

void Animation::Update(float deltaTime)
{
	m_iFrame++;

	if (m_bAutoPlay)
	{
		if(m_bEndWithFrame)
			if(!m_bEnd)
				if (m_iFrame > m_iDelay)
				{
					m_iCurrentFrame++;
					m_iFrame = 0;
				}
	}

	if (m_iCurrentFrame >= m_iLastFrame)
	{
		m_iCurrentFrame = 0;
		m_bEnd = 1;
	}

	m_Anim.at(m_iCurrentFrame)->Update(deltaTime);
}

void Animation::Render()
{
	m_Anim.at(m_iCurrentFrame)->Render();
}