#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include <direct.h>

#include "textureshaderclass.h"
#include "lightshaderclass.h"
#include "d3dclass.h"
#include "Renderer.h"
#include "LightManager.h"

#include "CameraObject.h"


class RenderManager {
private:
    std::vector<Renderer*> renderers;

public:
    static RenderManager& GetInstance() {
        static RenderManager instance;
        return instance;
    }

    bool InitializeRender(ID3D11Device* device);

    void RegisterRenderer(Renderer* renderer);

    void UnregisterRenderer(Renderer* renderer);

    bool RenderAll(LightShaderClass* LightShader, D3DClass* D3D, CameraObject* mainCamera, LightManager* lightManager, XMFLOAT4*, XMFLOAT4*);
    bool RenderAll(TextureShaderClass* TextureShader, D3DClass* D3D, XMMATRIX vMatrix);
};

#endif