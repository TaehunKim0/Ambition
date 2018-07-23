#pragma once
class Renderer : public Singleton<Renderer>
{
public:
	LPDIRECT3D9 m_Direct3d9;
	LPDIRECT3DDEVICE9 m_D3DDevice;
	LPD3DXSPRITE m_Sprite;

	

public:
	Renderer();
	~Renderer();

public:
	bool Init(int width, int height, bool windowMode);
	void Release();

	void Begin();
	void End();

	inline LPDIRECT3D9 GetD3D() {
		return m_Direct3d9;
	}
	inline LPDIRECT3DDEVICE9 GetDevice() {
		return m_D3DDevice;
	}
};

