#pragma once
#include "Script.h"
class PlayerScript :
    public Script
{
public:
	enum class eState
	{
		Idle,
		LeftWalk,
		RightWalk,
        Attack
	};
    PlayerScript();
    ~PlayerScript();

    void Initialize() override;
    void Update()override;
    void LateUpdate()override;
    void Render()override;

    void OnCollisionEnter(class Collider* other)override;
    void OnCollisionStay(class Collider* other)override;
    void OnCollisionExit(class Collider* other)override;

};

