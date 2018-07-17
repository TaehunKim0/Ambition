#pragma once
class Animation : public GameObject
{
private:
	vector<Sprite*> m_Anim;

	int m_iFrame;
	int m_iCurrentFrame;
	int m_iDelay;
	int m_iLastFrame;

public:
	bool m_bEnd;
	bool m_bAutoPlay;
	bool m_bEndWithFrame;
	bool m_bFrameZero;

	bool m_bPlay;

public:
	Animation();
	virtual ~Animation();

	void Init(bool autoplay, int delay, GameObject* parent);
	void Set();

public:
	void SetCurrentFrame(int frame);
	void SetAutoPlay(bool play);
	void SetAnimEndWithFrame(bool end); //�ִϸ��̼��� ������ �ִϸ��̼��� ������ΰ�
	void SetFrameZeroIsEnd(bool end); //�ִϸ��̼��� ������ �������� �ٽ� 0���� �ǵ��� ���ΰ�

public:
	void AddFrame(wstring fileName);
	void AddContinueFrame(wstring fileName, int firstFrame, int lastFrame);

	void Update(float deltaTime);
	void Render();

};