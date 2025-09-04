#include "PanelTextureClass.h"
#include "DDSTextureLoader.h"

using namespace DirectX;

PanelTextureClass::PanelTextureClass()
{
	m_texture = 0;
}


PanelTextureClass::PanelTextureClass(const PanelTextureClass& other)
{
}


PanelTextureClass::~PanelTextureClass()
{
}


bool PanelTextureClass::Initialize(ID3D11Device* device, const WCHAR* filename)
{
	HRESULT result;

	// Load texture data from a file by using DDS texture loader.
	result = CreateDDSTextureFromFile(device, filename, nullptr, &m_texture);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}


void PanelTextureClass::Shutdown()
{
	// Release the texture resource.
	if (m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	return;
}


ID3D11ShaderResourceView* PanelTextureClass::GetTexture()
{
	return m_texture;
}