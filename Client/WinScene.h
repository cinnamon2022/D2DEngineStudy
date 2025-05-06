#pragma once
#include "../Source/Scene.h"

class WinScene : public Scene
{
public:
	WinScene();
	virtual ~WinScene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
};

