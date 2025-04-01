#pragma once
#include "../Source/Scene.h"

class EndingScene : public Scene
{
public:
	EndingScene();
	virtual ~EndingScene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
private:

};