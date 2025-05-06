#pragma once
#include "../Source/Script.h"
class EnemyScript : public Script
{
public:
    EnemyScript();
    ~EnemyScript();

    void Initialize() override;
    void Update()override;
    void LateUpdate()override;
    void Render()override;

    void OnCollisionEnter(class Collider* other)override;
    void OnCollisionStay(class Collider* other)override;
    void OnCollisionExit(class Collider* other)override;
private:
    float timer = 0;
    float speed = 100.f;
};

