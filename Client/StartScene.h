#pragma once
#include "../Source/Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
private:

};