////////////////////////////////////////////////////////////////////////////////
// Filename: PanelModelClass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _PANELMODELCLASS_H_
#define _PANELMODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <directxmath.h>

using namespace DirectX;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Class name: ModelClass
////////////////////////////////////////////////////////////////////////////////
class PanelModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
	};

	struct FaceType
	{
		int vIndex1, vIndex2, vIndex3;
		int tIndex1, tIndex2, tIndex3;
		int nIndex1, nIndex2, nIndex3;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct InstanceType
	{
		XMFLOAT3 position;
		float padding;
	};

public:
	PanelModelClass();

	PanelModelClass(const PanelModelClass&);
	~PanelModelClass();

	bool InitializeRender(ID3D11Device*, const WCHAR*, int, XMFLOAT4);
	bool Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	int GetInstanceCount();
	ID3D11ShaderResourceView* GetTexture();

	bool LoadModel(const WCHAR*, XMFLOAT4);
	void ReleaseModel();

	bool ReadFileCounts(const WCHAR*, XMFLOAT4);
	bool LoadDataStructures(const WCHAR*, int, int, int, int, XMFLOAT4);

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, const WCHAR*);
	void ReleaseTexture();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	ID3D11Buffer* m_instanceBuffer;
	int m_vertexCount, m_indexCount, m_textureCount, m_normalCount, m_faceCount, m_instanceCount;
	TextureClass* m_Texture;

	ModelType* m_model;
};

#endif