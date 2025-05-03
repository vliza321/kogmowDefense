#include "CanvasRenderManager.h"

bool CanvasRenderManager::RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX vMatrix)
{
    bool result = true;
    XMMATRIX viewMatrix, worldMatrix, orthoMatrix;
    D3D->GetWorldMatrix(worldMatrix);
    D3D->GetOrthoMatrix(orthoMatrix);

    XMVECTOR position = XMVectorSet(0.0f, 0.0f, 10.0f, 0.0f);
    XMVECTOR lookAt = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
    XMVECTOR up = XMVectorSet(0.0f, 01.0f, 0.0f, 0.0f);

    viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active)
        {
            /*
            auto RenderTransform = renderer->gameObject->GetComponent<Transform>().get();
            if (!RenderTransform) return;

            rotationMatrix = XMMatrixRotationX(RenderTransform->rotation.x)
                * XMMatrixRotationY(RenderTransform->rotation.y)
                * XMMatrixRotationZ(RenderTransform->rotation.z)
                * XMMatrixRotationRollPitchYaw(RenderTransform->eulerRotation.x, RenderTransform->eulerRotation.y, 0);

            worldMatrix = XMMatrixScaling(RenderTransform->scale.x, RenderTransform->scale.y, RenderTransform->scale.z)
                * XMMatrixTranslation(RenderTransform->position.x, RenderTransform->position.y, RenderTransform->position.z);
                */
            renderer->Render(D3D->GetDeviceContext());
            result = TextureShader->Render(D3D->GetDeviceContext(),
                renderer->GetModelIndexCount(), renderer->GetModelInstanceCount(),
                worldMatrix, worldMatrix, viewMatrix, orthoMatrix,
                renderer->GetModelTexture()
            );
            if (!result) return result;
        }
    }
    return result;
}