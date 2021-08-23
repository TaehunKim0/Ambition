#pragma once
class Animation : public GameObject
{
public:
	std::vector<Sprite*> m_Anim;
	int m_Delay;
	int m_CurrentFrame;
	int m_LastFrame;

	int m_Frame;

	bool m_End;
	bool m_Middle;
	bool m_AutoPlay;

	bool BAutoWhenEnd;

	void SetRed();

public:
	Animation();
	~Animation();

	void Init(int delay, bool autoplay) {
		m_Delay = delay;
		m_AutoPlay = autoplay;
	}

	void AddFrame(std::string fileName);
	void AddContinueFrame(std::string fileName, int startFrame, int lastFrame);

	void Update(float deltaTime);
	void Render();

};