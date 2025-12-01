#ifndef _SCENECHANGERCONTROLLER_H
#define _SCENECHANGERCONTROLLER_H


#include "Component.h"
class SceneChangerController :
    public Component
{
public:
    SceneChangerController();
    ~SceneChangerController();

    virtual void Execute() override;
private:
    float const POVMAXTIMER = 300.0f;
    float PoVTimer;
    bool canChangePov;
};

#endif // !
