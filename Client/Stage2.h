#pragma once
#include "../Source/Scene.h"

class Stage2 : public Scene
{
public:
	Stage2();
	virtual ~Stage2();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
private:

};