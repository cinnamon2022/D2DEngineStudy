#pragma once
#include "Script.h"
class PlayerScript :
    public Script
{
public:
    PlayerScript();
    ~PlayerScript();

    void Initialize() override;
    void Update()override;
    void LateUpdate()override;
    void Render()override;

};

