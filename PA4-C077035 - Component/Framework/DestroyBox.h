#ifndef _DESTROYBOX_H
#define _DESTROYBOX_H

#pragma once
#include "Component.h"
class DestroyBox :
    public Component
{
public:
    DestroyBox() : Component()
    {

    }
    ~DestroyBox()
    {

    }
    virtual void OnCollisionEnter(Collider* other) override;
};

#endif // 
