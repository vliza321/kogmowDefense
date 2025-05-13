#ifndef CANVAS_RENDERER_H
#define CANVAS_RENDERER_H

#pragma once
#include <memory>
#include "Component.h"
#include "modelclass.h"
#include "PanelModelClass.h"
#include "textureclass.h"
#include "RenderComponent.h"
#include "RectTransform.h"

class CanvasRenderer : public Component, public RenderComponent
{
public:
	CanvasRenderer(const WCHAR* TextureFilename, XMFLOAT4 PanelRect);
	~CanvasRenderer();
public:
	bool InitializeSet() override;
	bool InitializeRef() override;
	bool InitializeRender(ID3D11Device*) override;
	void Render(ID3D11DeviceContext*);
	bool Shutdown() override;

	ID3D11ShaderResourceView* GetModelTexture();
	PanelModelClass* GetModelData();

	ModelClass* GetModelData1();

	int GetModelIndexCount();
	int GetModelVertexCount();
	int GetModelInstanceCount();

	RectTransform* GetRectTransform();
private:
	ModelClass* m_baseModel;
	PanelModelClass* m_model;
	std::shared_ptr<RectTransform> m_rectTransform;
private:
	const WCHAR* m_modelFileName;
	const WCHAR* m_textureFileName;
	int m_instanceCounter;
};

#endif