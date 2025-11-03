#ifndef WORLD_SPACE_UI_RENDERER_H
#define WORLD_SPACE_UI_RENDERER_H

#pragma once
#include "PanelModelClass.h"
#include "textureclass.h"

#include "Component.h"
#include "RenderComponent.h"

#include "RectTransform.h"
#include "Transform.h"
#include "CameraManager.h"

class WorldSpaceUIRenderer : public Component, public RenderComponent
{
public:
	WorldSpaceUIRenderer(const WCHAR* TextureFilename, int InstanceCoutner);
	~WorldSpaceUIRenderer();
public:
	bool InitializeSet() override;
	bool InitializeRef() override;
	bool InitializeRender(ID3D11Device*) override;
	void Render(ID3D11DeviceContext*) override;
	void PostExecute();
	bool Shutdown();

	ID3D11ShaderResourceView* GetModelTexture();
	PanelModelClass* GetModelData();

	int GetModelIndexCount();
	int GetModelVertexCount();
	int GetModelInstanceCount();
private:
	PanelModelClass* m_model;
	std::weak_ptr<RectTransform> m_rectTransform;
	std::weak_ptr<Transform> m_transform;
	std::weak_ptr<CameraManager> m_cameraManager;
private:
	const WCHAR* m_modelFileName;
	const WCHAR* m_textureFileName;
	int m_instanceCounter;
};

#endif


