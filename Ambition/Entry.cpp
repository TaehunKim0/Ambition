#include"stdafx.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Application* App = Application::GetInst();
	
	App->Init(L"Ambition", 1920, 1280, 1);
	App->Run();
	App->Release();

	return 0;
}