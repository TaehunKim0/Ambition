#pragma once
class GamDok : public Singleton<GamDok>
{
public:
	GameObject * m_CurrentScene;
public:
	GamDok();
	~GamDok();

	void Change(GameObject* scene);

	void Update(float deltaTime);
	void Render();

};

