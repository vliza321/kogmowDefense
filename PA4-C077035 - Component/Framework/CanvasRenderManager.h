#ifndef CANVAS_RENDER_MANAGER_H
#define CANVAS_RENDER_MANAGER_H

#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "d3dclass.h"
#include "CanvasRenderer.h"
#include "textureshaderclass.h"
#include "Transform.h"

class CanvasRenderManager {
private:
    std::vector<CanvasRenderer*> renderers;

public:
    static CanvasRenderManager& GetInstance() {
        static CanvasRenderManager instance;
        return instance;
    }

    bool InitializeRender(ID3D11Device* Device)
    {
        for (auto& render : renderers)
        {
            if (!render->InitializeRender(Device))
            {
                return false;
            }
        }

        return true;
    }

    void RegisterRenderer(CanvasRenderer* renderer) {
        renderers.emplace_back(renderer);
    }

    void UnregisterRenderer(CanvasRenderer* renderer) {
        renderers.erase(std::remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }

    bool RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX vMatrix);
};

#endif // !RENDER_MANAGER_H

