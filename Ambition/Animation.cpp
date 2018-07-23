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
	, m_bFrameZero(1)
	, m_bAnimMiddle(0)
	, m_iMiddleFrame(0)
{
}

Animation::~Animation()
{
}

void Animation::Init(bool autoplay, int delay, GameObject* parent)
{
	m_bAutoPlay = autoplay;
	m_iDelay = delay;
	SetParent(parent);
}

void Animation::Set()
{
	m_bEnd = false;
	m_bAnimMiddle = false;
	m_iFrame = 0;
	m_iCurrentFrame = 0;
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

void Animation::SetFrameZeroIsEnd(bool end)
{
	m_bFrameZero = end;
}

void Animation::AddFrame(wstring fileName)
{
	auto sprite = Sprite::Create(fileName);
	sprite->SetParent(this);

	if (sprite)
		m_Anim.push_back(sprite);

	m_iLastFrame++;

}

void Animation::AddContinueFrame(wstring fileName, int firstFrame, int lastFrame)
{
	if (firstFrame > lastFrame)
	{
		for (int i = firstFrame; i >= lastFrame; i--)
		{
			auto sprite = Sprite::Create(fileName.c_str() + to_wstring(i) + L".png");

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);

			m_iLastFrame++;
		}
	}
	else
	{
		for (int i = firstFrame; i <= lastFrame; i++)
		{
			auto sprite = Sprite::Create(fileName.c_str() + to_wstring(i) + L".png");

			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);

			m_iLastFrame++;
		}
	}

}

void Animation::Update(float deltaTime)
{
	if(!m_bEnd)
		m_iFrame++;

	if (m_bAutoPlay)
	{
		if (m_iFrame > m_iDelay)
		{
			m_iCurrentFrame++;
			m_iFrame = 0;
		}
	}
	m_iMiddleFrame = m_iLastFrame / 2;

	if (m_iLastFrame / 2 == m_iCurrentFrame)
		m_bAnimMiddle = true;

	if (m_iCurrentFrame >= m_iLastFrame)
	{
		if (m_bFrameZero)
			m_iCurrentFrame = 0;
		else
			m_iCurrentFrame--;

		if(m_bEndWithFrame)
			m_bEnd = 1;
	}

	

	m_Anim.at(m_iCurrentFrame)->Update(deltaTime);
}

void Animation::Render()
{
	m_Anim.at(m_iCurrentFrame)->Render();
}