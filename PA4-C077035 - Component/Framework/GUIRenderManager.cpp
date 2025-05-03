#include "GUIRenderManager.h"

bool GUIRenderManager::RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX viewMatrix)
{
    bool result = true;
    XMMATRIX rotationMatrix, worldMatrix, projectionMatrix;
    D3D->GetProjectionMatrix(projectionMatrix);
    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            auto RenderTransform = renderer->gameObject->GetComponent<Transform>().get();
            if (!RenderTransform) continue;
            rotationMatrix = XMMatrixRotationX(RenderTransform->rotation.x)
                * XMMatrixRotationY(RenderTransform->rotation.y)
                * XMMatrixRotationZ(RenderTransform->rotation.z)
                * XMMatrixRotationRollPitchYaw(RenderTransform->eulerRotation.x, RenderTransform->eulerRotation.y, 0);

            worldMatrix = XMMatrixScaling(RenderTransform->scale.x, RenderTransform->scale.y, RenderTransform->scale.z)
                * XMMatrixTranslation(RenderTransform->position.x, RenderTransform->position.y, RenderTransform->position.z);

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