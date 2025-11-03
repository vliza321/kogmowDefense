#include "WorldSpaceUIRenderManager.h"

WorldSpaceUIRenderManager::WorldSpaceUIRenderManager()
{
}

WorldSpaceUIRenderManager::~WorldSpaceUIRenderManager()
{
}

bool WorldSpaceUIRenderManager::RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX viewMatrix)
{
    bool result = true;
    XMMATRIX rotationMatrix, worldMatrix, projectionMatrix;
    D3D->GetProjectionMatrix(projectionMatrix);

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponent<Transform>().get();
            if (!RenderTransform) continue;
            rotationMatrix = XMMatrixIdentity();

            worldMatrix = RenderTransform->WorldMatrix;

            renderer->Render(D3D->GetDeviceContext());
            result = TextureShader->Render(D3D->GetDeviceContext(),
                renderer->GetModelIndexCount(), renderer->GetModelInstanceCount(),
                rotationMatrix, worldMatrix, viewMatrix, projectionMatrix,
                renderer->GetModelTexture()
            );
            if (!result) return result;
        }
    }
    return result;
}

bool WorldSpaceUIRenderManager::Shutdown()
{
    bool result = true;
    for (auto& renderer : renderers) {
        if (!renderer->Shutdown())
            return false;
    }
    renderers.clear();
    return result;
}
