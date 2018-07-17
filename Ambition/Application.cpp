#include "stdafx.h"
#include "Application.h"


Application::Application()
{
}


Application::~Application()
{
}

bool Application::Init(wstring title, int width, int height, bool windowMode)
{
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

	m_Title = title;
	m_iWidth = width;
	m_iHeight = height;
	m_bWindowed = windowMode;

	if (!(_CreateWindow()))
		return false;
	if (!(_CreateRenderer()))
		return false;

	srand(time(NULL));

	return true;
}

void Application::Release()
{
	Renderer::GetInst()->Release();
	FreeConsole();
}

#include"Main.h"
void Application::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	Main* main = new Main();
	main->Init();
	SceneDirector::GetInst()->ChangeScene(main);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 1, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Renderer::GetInst()->Begin();
			SceneDirector::GetInst()->Update(60.f);
			SceneDirector::GetInst()->Render();
			Renderer::GetInst()->End();

			if (InputSystem->GetKey(VK_ESCAPE) == KeyState::UP)
				exit(0);
		}

	}

}

bool Application::_CreateWindow()
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = m_Title.c_str();
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	if (RegisterClass(&wc) == false)
		return false;

	DWORD Style;
	if (m_bWindowed)
		Style = WS_OVERLAPPEDWINDOW;
	else
		Style = WS_POPUP | WS_EX_TOPMOST;

	m_Handle = CreateWindow(m_Title.c_str(), m_Title.c_str(), Style, 0, 0, m_iWidth, m_iHeight, NULL, NULL, NULL, NULL);

	if (m_Handle == nullptr)
		return false;

	ShowWindow(m_Handle, SW_SHOWDEFAULT);
	UpdateWindow(m_Handle);

	return true;
}

bool Application::_CreateRenderer()
{
	if (!(Renderer::GetInst()->Init(m_iWidth, m_iHeight, m_bWindowed)))
		return false;

	return true;
}

LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
