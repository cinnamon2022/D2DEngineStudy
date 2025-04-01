#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render() override;

private:
};
