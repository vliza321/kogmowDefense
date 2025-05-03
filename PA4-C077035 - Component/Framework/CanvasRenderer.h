#ifndef CANVAS_RENDERER_H
#define CANVAS_RENDERER_H

#pragma once
#include <memory>
#include "Component.h"
#include "PanelModelClass.h"
#include "textureclass.h"
#include "RenderComponent.h"
#include "RectTransform.h"

class CanvasRenderer : public Component, public RenderComponent
{
public:
	CanvasRenderer(const WCHAR* TextureFilename, int InstanceCoutner);
	~CanvasRenderer();
public:
	bool InitializeSet() override;
	bool InitializeRef() override;
	bool InitializeRender(ID3D11Device*) override;
	void Render(ID3D11DeviceContext*);
	bool Shutdown() override;

	ID3D11ShaderResourceView* GetModelTexture();
	PanelModelClass* GetModelData();

	int GetModelIndexCount();
	int GetModelVertexCount();
	int GetModelInstanceCount();
private:
	PanelModelClass* m_model;
	std::weak_ptr<RectTransform> m_rectTransform;
private:
	const WCHAR* m_modelFileName;
	const WCHAR* m_textureFileName;
	int m_instanceCounter;
};

#endif