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

bool RenderManager::RenderAll(LightShaderClass* LightShader, D3DClass* D3D, CameraObject* mainCamera, LightManager* lightManager, XMFLOAT4* lightDeffuserColor, XMFLOAT4* lightPosition)
{
    bool result = true;
    XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
    viewMatrix = mainCamera->GetViewMatrix();
    D3D->GetProjectionMatrix(projectionMatrix);

    auto ct = mainCamera->gameObject->GetComponentIncludingBase<Transform>().get();

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponentIncludingBase<Transform>().get();
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
                ct->position,
                lightManager->GetDirectionalLight()->specularColor, lightManager->GetDirectionalLight()->specularPower,
                lightDeffuserColor,lightPosition);

            if (!result) return result;
        }
    }
    return result;
}

bool RenderManager::RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX vMatrix)
{
    bool result = true;
    XMMATRIX worldMatrix, viewMatrix, projectionMatrix;

    D3D->GetWorldMatrix(worldMatrix);
    D3D->GetOrthoMatrix(projectionMatrix);

    XMVECTOR position = XMVectorSet(0.0f, 0.0f, -10.0f, 0.0f);
    XMVECTOR lookAt = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
    XMVECTOR up = XMVectorSet(0.0f, -01.0f, 0.0f, 0.0f);

    viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponentIncludingBase<Transform>().get();
            if (!RenderTransform) break;

            renderer->Render(D3D->GetDeviceContext());
            result = TextureShader->Render(D3D->GetDeviceContext(),
                renderer->GetModelIndexCount(), renderer->GetModelInstanceCount(),
                worldMatrix, worldMatrix, viewMatrix, projectionMatrix,
                renderer->GetModelTexture());

            if (!result) return result;
        }
    }
    return result;
}

