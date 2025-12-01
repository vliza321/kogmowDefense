#include "RenderManager.h"
#include "Renderer.h"
#include "GameScene.h"

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}


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

bool RenderManager::RenderAll(LightShaderClass* LightShader, D3DClass* D3D, CameraObject* mainCamera, LightManager* lightManager, XMFLOAT4* lightDiffuserColor, XMFLOAT4* lightPosition)
{
    bool result = true;
    XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
    viewMatrix = mainCamera->GetViewMatrix();
    D3D->GetProjectionMatrix(projectionMatrix);

    auto cameraPosition = mainCamera->GetPosition();

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponent<Transform>().get();
            if (!RenderTransform) break;

            worldMatrix = RenderTransform->WorldMatrix;

            renderer->Render(D3D->GetDeviceContext());
            result = LightShader->Render(D3D->GetDeviceContext(),
                renderer->GetModelIndexCount(), renderer->GetModelInstanceCount(),
                worldMatrix, viewMatrix, projectionMatrix,
                renderer->GetModelTextureArray(),
                lightManager->GetDirectionalLight()->direction, lightManager->GetDirectionalLight()->ambientColor, lightManager->GetDirectionalLight()->diffuseColor,
                cameraPosition,
                lightManager->GetDirectionalLight()->specularColor, lightManager->GetDirectionalLight()->specularPower,
                lightDiffuserColor,lightPosition);

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

bool RenderManager::Shutdown()
{
    bool result = true;
    for (auto& renderer : renderers) {
        if (!renderer->Shutdown())
            return false;
    }
    renderers.clear();
    return result;
}

