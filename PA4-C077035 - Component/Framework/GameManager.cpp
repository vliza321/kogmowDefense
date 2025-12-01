#include "GameManager.h"
#include "ObjectClass.h"
#include "SceneManager.h"
#include "GameObject.h"

bool GameManager::InitializeRef()
{
    auto player = FindObjectWithTag(Tag::Player);
    if (player != nullptr)
    {
        m_player = player->GetComponent<Player>().get();
    }
    m_resultUI = this->GetComponent<CanvasRenderer>().get();

    return true;
}

bool GameManager::PostInitialize()
{
    m_resultUI->active = false;
    return true;
}

void GameManager::Execute()
{
    auto& input = Input();
    if (m_boxCount == 0)
    {
        m_resultUI->active = true;
        m_player->active = false;
        if (input.GetCurrMouseState().rgbButtons[0])
        {
            SCENEMANAGER.StartScene(0);
        }
    }

}
