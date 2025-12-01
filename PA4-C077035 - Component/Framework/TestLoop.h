#pragma once
#include "Component.h"
#include "Transform.h"

class TestLoop :
    public Component
{
public:
    TestLoop();
    ~TestLoop();

    virtual bool InitializeRef() override;

    virtual void Execute() override;

private:
    std::weak_ptr<Transform> transform;
};

