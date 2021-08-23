#pragma once
class App : public Singleton<App>
{
public:
	int m_Width;
	int m_Height;
	bool m_WindowMode;
	HWND m_Handle;

	//
	LPDIRECT3D9 m_Direct;
	LPDIRECT3DDEVICE9 m_Dev;
	LPD3DXSPRITE m_Sprite;

	

public:
	App();
	~App();

	void Release() {
		m_Direct->Release();
		m_Dev->Release();
		m_Sprite->Release();
		FreeConsole();
	}
public:
	void Run();
	void Begin();
	void End();

	void Init(int width, int height, bool mode);

	bool _CreateWindow();
	bool _CreateRenderer();

	static LRESULT CALLBACK WndProc(HWND h, UINT m, WPARAM w, LPARAM l);

};

