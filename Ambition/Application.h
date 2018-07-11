#pragma once
class Application : public Singleton<Application>
{
public:
	HWND m_Handle;

	int m_iWidth;
	int m_iHeight;
	bool m_bWindowed;

	wstring m_Title;

public:
	Application();
	~Application();

public:
	bool Init(wstring title, int width, int height, bool windowMode);
	void Release();

	void Run();

	bool _CreateWindow();
	bool _CreateRenderer();

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


};

