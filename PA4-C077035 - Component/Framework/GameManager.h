#pragma once
#include "Component.h"
#include "CanvasRenderer.h"
#include "Player.h"

class GameManager :
    public Component
{
public:
    GameManager(int i) : Component(), m_boxCount(i)
    {
        m_resultUI = nullptr;
        m_player = nullptr;
    }
    ~GameManager()
    {
        m_resultUI = nullptr;
        m_player = nullptr;
    }

    virtual bool InitializeRef() override;
    virtual bool PostInitialize() override;
    virtual void Execute() override;

    int m_boxCount;
    CanvasRenderer* m_resultUI;
    Player* m_player;
};

