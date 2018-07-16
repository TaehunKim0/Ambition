#pragma once

enum class KeyState
{
	DOWN,
	UP,
	PRESS,
	NONE
};

class Input : public Singleton<Input>
{
private:



public:
	Input();
	~Input();

public:
	void Update();

};