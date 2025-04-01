#pragma once
#include "../Source/Scene.h"

class Stage1 : public Scene
{
public:
	Stage1();
	virtual ~Stage1();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
private:

};

