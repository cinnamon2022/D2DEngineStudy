#pragma once
#include "../Source/Scene.h"

class Player;

class Stage1 : public Scene
{
public:
	Stage1();
	virtual ~Stage1();

	void Enter();
	void Exit();

	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	
private:
	Player* dino;
};

