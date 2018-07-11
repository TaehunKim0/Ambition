#pragma once
class SceneDirector : public Singleton<SceneDirector>
{
public:
	GameObject * m_CurrentScene;

public:
	SceneDirector();
	~SceneDirector();

public:
	void ChangeScene(GameObject* scene);

	void Update(float deltaTime);
	void Render();

};

