#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

bool Renderer::Init(int width, int height, bool windowMode)
{
	m_Direct3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS pp = {};
	pp.Windowed = windowMode;
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	if (FAILED(m_Direct3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Application::GetInst()->m_Handle, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_D3DDevice)))
	{
		MessageBox(nullptr, L"Devide Create Arror", L"Arror", MB_OK);
		return false;
	}

	if FAILED(D3DXCreateSprite(m_D3DDevice, &m_Sprite))
		return false;

	return true;
}

void Renderer::Release()
{
	m_Direct3d9->Release();
	m_D3DDevice->Release();
	m_Sprite->Release();
}

void Renderer::Begin()
{
	m_D3DDevice->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 125, 125), 1.0f, 0.f);
	m_D3DDevice->BeginScene();
}

void Renderer::End()
{
	m_D3DDevice->EndScene();
	m_D3DDevice->Present(NULL, NULL, NULL, NULL);
}
