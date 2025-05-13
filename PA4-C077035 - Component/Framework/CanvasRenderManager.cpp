#include "CanvasRenderManager.h"

bool CanvasRenderManager::RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX vMatrix)
{
    bool result = true;
    XMMATRIX worldMatrix, viewMatrix, orthoMatrix;

    D3D->GetWorldMatrix(worldMatrix);
    D3D->GetOrthoMatrix(orthoMatrix);

    XMVECTOR position = XMVectorSet(0.0f, 0.0f, -10.0f, 0.0f);
    XMVECTOR lookAt = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
    XMVECTOR up = XMVectorSet(0.0f, -01.0f, 0.0f, 0.0f);

    viewMatrix = XMMatrixLookAtLH(position, lookAt, up);

    for (auto& renderer : renderers) {
        if (renderer->gameObject->active && renderer->active)
        {
            if (!renderer->GetRectTransform()) break;

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