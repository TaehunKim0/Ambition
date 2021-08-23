#include "stdafx.h"
#include "App.h"
#include"Time.h"
#include"SMain.h"

App::App()
{
}


App::~App()
{
}

void App::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 1, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Time::CurrentTime += 1;
			Time::TotalTime += 1;


			if (Time::CurrentTime > 60)
				Time::CurrentTime = 0;

			Begin();
			GamDok::Get()->Update(60.f);
			GamDok::Get()->Render();
			End();

			if (IInput->GetKey(VK_F1) == KeyState::DOWN)
				exit(0);

			if (IInput->GetKey(VK_F3) == KeyState::DOWN)
				GamDok::Get()->Change(new SMain());
		}
	}



}

void App::Begin()
{
	m_Dev->Clear(1, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 128, 128), 1, 0);
	m_Dev->BeginScene();
}

void App::End()
{
	m_Dev->EndScene();
	m_Dev->Present(NULL, NULL, NULL, NULL);
}

void App::Init(int width, int height, bool mode)
{
	m_Width = width;
	m_Height = height;
	m_WindowMode = mode;

	if (!_CreateWindow())
		return;
	if (!_CreateRenderer())
		return;
}

bool App::_CreateWindow()
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Ambition";
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	RegisterClass(&wc);

	DWORD Style = 0;

	if (m_WindowMode)
		Style = WS_POPUP;
	else
		Style = WS_POPUP | WS_EX_TOPMOST;

	m_Handle = CreateWindow("Ambition", "Ambition", Style, 0, 0, m_Width, m_Height, NULL, NULL, NULL, NULL);

	if (m_Handle == NULL)
		return false;

	ShowWindow(m_Handle, SW_SHOWDEFAULT);
	UpdateWindow(m_Handle);


	return true;
}

bool App::_CreateRenderer()
{
	m_Direct = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferWidth = m_Width;
	pp.BackBufferHeight = m_Height;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = m_WindowMode;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.hDeviceWindow = m_Handle;

	m_Direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_Handle, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_Dev);

	D3DXCreateSprite(m_Dev, &m_Sprite);
	
	return true;
}

LRESULT App::WndProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
	switch (m)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(h, m, w, l);
}
