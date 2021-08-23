#include"stdafx.h"
#include"SMain.h"
#include"SIntro.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	FILE*stream;
	AllocConsole();
	freopen_s(&stream, "CONOUT$", "wt", stdout);
	
	srand(time(NULL));

	App::Get()->Init(1920, 1080, 0);

	GamDok::Get()->Change(new SMain());

	App::Get()->Run();
	App::Get()->Release();

	return 0;
}