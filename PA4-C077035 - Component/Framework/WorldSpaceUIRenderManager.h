#ifndef WORLD_SPACE_UI_RENDER_MANAGER_H
#define WORLD_SPACE_UI_RENDER_MANAGER_H

#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "d3dclass.h"
#include "WorldSpaceUIRenderer.h"
#include "textureshaderclass.h"
#include "Transform.h"

class WorldSpaceUIRenderManager {
private:
    std::vector<WorldSpaceUIRenderer*> renderers;

public:
    WorldSpaceUIRenderManager();
    ~WorldSpaceUIRenderManager();

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

    void RegisterRenderer(WorldSpaceUIRenderer* Renderer) {
        renderers.emplace_back(Renderer);
    }

    void UnregisterRenderer(WorldSpaceUIRenderer* Renderer) {
        renderers.erase(std::remove(renderers.begin(), renderers.end(), Renderer), renderers.end());
    }

    bool RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX viewMatrix);

    bool Shutdown();
};

#endif

