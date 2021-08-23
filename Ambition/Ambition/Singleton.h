#pragma once
template<class T>
class Singleton
{
public:
	static T* inst;

	Singleton() {

	}
	~Singleton()
	{

	}

public:
	static T* Get()
	{
		if (inst == nullptr)
			inst = new T();

		return inst;
	}


};

template<class T>
T* Singleton<T>::inst = nullptr;