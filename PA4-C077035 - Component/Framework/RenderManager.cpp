#include "RenderManager.h"
#include "Renderer.h"

bool RenderManager::InitializeRender(ID3D11Device* device)
{
    for (auto& render : renderers)
    {
        if (!render->InitializeRender(device))
        {
            return false;
        }
    }

    return true;
}

void RenderManager::RegisterRenderer(Renderer* renderer)
{
    renderers.emplace_back(renderer);
}

void RenderManager::UnregisterRenderer(Renderer* renderer)
{
    renderers.erase(std::remove(renderers.begin(), renderers.end(), renderer), renderers.end());
}

bool RenderManager::RenderAll(LightShaderClass* LightShader, D3DClass* D3D, CameraObject* mainCamera, LightManager* lightManager)
{
    bool result = true;
    XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
    viewMatrix = mainCamera->GetViewMatrix();
    D3D->GetProjectionMatrix(projectionMatrix);
    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponent<Transform>().get();
            if (!RenderTransform) break;

            worldMatrix = XMMatrixScaling(RenderTransform->scale.x, RenderTransform->scale.y, RenderTransform->scale.z)
                * XMMatrixRotationX(RenderTransform->rotation.x)
                * XMMatrixRotationY(RenderTransform->rotation.y)
                * XMMatrixRotationZ(RenderTransform->rotation.z)
                * XMMatrixRotationRollPitchYaw(RenderTransform->eulerRotation.x, RenderTransform->eulerRotation.y, 0)
                * XMMatrixTranslation(RenderTransform->position.x, RenderTransform->position.y, RenderTransform->position.z);

            renderer->Render(D3D->GetDeviceContext());
            result = LightShader->Render(D3D->GetDeviceContext(),
                renderer->GetModelIndexCount(), renderer->GetModelInstanceCount(),
                worldMatrix, viewMatrix, projectionMatrix,
                renderer->GetModelTexture(),
                lightManager->GetDirectionalLight()->direction, lightManager->GetDirectionalLight()->ambientColor, lightManager->GetDirectionalLight()->diffuseColor,
                mainCamera->gameObject->GetComponent<Transform>()->position,
                lightManager->GetDirectionalLight()->specularColor, lightManager->GetDirectionalLight()->specularPower,
                lightManager->GetDiffusers(), lightManager->GetPositions());

            if (!result) return result;
        }
    }
    return result;
}


