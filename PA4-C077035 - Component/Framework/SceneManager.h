#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "SceneSystem.h"

class SceneManager : public SceneSystem
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}

public:
	bool LoadScene(int);
	bool LoadScene(string);

	bool StartScene();
	bool StartScene(int count);
	bool StartScene(string sceneName);
};

#endif 