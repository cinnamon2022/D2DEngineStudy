#pragma once
#include "Component.h"
class Script :public Component
{
public:

	Script();
	~Script();

	void Initialize() override;
	void Update()override;
	void LateUpdate()override;
	void Render()override;
private:

	 
};

