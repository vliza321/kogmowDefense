#ifndef GUI_RENDER_MANAGER_H
#define GUI_RENDER_MANAGER_H

#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "d3dclass.h"
#include "GUIRenderer.h"
#include "textureshaderclass.h"
#include "Transform.h"

class GUIRenderManager {
private:
    std::vector<GUIRenderer*> renderers;

public:
    static GUIRenderManager& GetInstance() {
        static GUIRenderManager instance;
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

    void RegisterRenderer(GUIRenderer* Renderer) {
        renderers.emplace_back(Renderer);
    }

    void UnregisterRenderer(GUIRenderer* Renderer) {
        renderers.erase(std::remove(renderers.begin(), renderers.end(), Renderer), renderers.end());
    }

    bool RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX viewMatrix);
};

#endif

