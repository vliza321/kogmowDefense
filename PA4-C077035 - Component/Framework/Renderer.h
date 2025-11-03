#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include "modelclass.h"
#include "textureclass.h"
#include "Component.h"
#include "RenderComponent.h"

class Renderer : public Component, public RenderComponent
{
public:
	Renderer(const WCHAR* ModelFilename, const WCHAR* TextureFilename, int InstanceCoutner);
	~Renderer();
public:
	bool InitializeSet() override;
	bool InitializeRef() override;
	bool InitializeRender(ID3D11Device*) override;
	void Render(ID3D11DeviceContext*) override;
	bool Shutdown() override;

	ID3D11ShaderResourceView* GetModelTexture();
	ID3D11ShaderResourceView** GetModelTextureArray();
	ModelClass* GetModelData();

	int GetModelIndexCount();
	int GetModelVertexCount();
	int GetModelInstanceCount();
private:
	ModelClass* m_model;
private:
	const WCHAR* m_modelFileName;
	const WCHAR* m_textureFileName;
	int m_instanceCounter;
};

#endif // !RENDERER_H
