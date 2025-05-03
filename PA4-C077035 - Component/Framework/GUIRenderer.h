#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#pragma once
#include "Component.h"
#include "PanelModelClass.h"
#include "textureclass.h"
#include "RenderComponent.h"
#include "RectTransform.h"

class GUIRenderer : public Component, public RenderComponent
{
public:
	GUIRenderer(const WCHAR* TextureFilename, int InstanceCoutner);
	~GUIRenderer();
public:
	bool InitializeSet() override;
	bool InitializeRef() override;
	bool InitializeRender(ID3D11Device*) override;
	void Render(ID3D11DeviceContext*);
	bool Shutdown();

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


