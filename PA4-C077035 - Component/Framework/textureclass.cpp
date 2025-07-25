////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "textureclass.h"
#include "DDSTextureLoader.h"

using namespace DirectX;

TextureClass::TextureClass()
{
	m_texture = 0;
}


TextureClass::TextureClass(const TextureClass& other)
{
}


TextureClass::~TextureClass()
{
}


bool TextureClass::Initialize(ID3D11Device* device, const WCHAR* filename)
{
	HRESULT result;
	WCHAR* texturefilename = (WCHAR*)(filename);

	std::wstring Texture1Filename = L"./data/" + std::wstring(texturefilename) + L"T1.dds";
	std::wstring Texture2Filename = L"./data/" + std::wstring(texturefilename) + L"T2.dds";
	std::wstring Alpha1Filename = L"./data/" + std::wstring(texturefilename) + L"A1.dds";
	std::wstring Alpha2Filename = L"./data/" + std::wstring(texturefilename) + L"A2.dds";
	std::wstring LightFilename = L"./data/" + std::wstring(texturefilename) + L"L.dds";
	std::wstring DumpFilename = L"./data/" + std::wstring(texturefilename) + L"D.dds";
	std::wstring SpecularFilename = L"./data/" + std::wstring(texturefilename) + L"S.dds";

	// Load texture data from a file by using DDS texture loader.
	result = CreateDDSTextureFromFile(device, filename, nullptr, &m_texture);
	if (FAILED(result))
	{
		return false;
	}

	// Load texture data from a file by using DDS texture loader.
	result = CreateDDSTextureFromFile(device, Texture1Filename.c_str(), nullptr, &m_textures[0]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[0]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, Texture2Filename.c_str(), nullptr, &m_textures[1]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[1]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, Alpha1Filename.c_str(), nullptr, &m_textures[2]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[2]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, Alpha2Filename.c_str(), nullptr, &m_textures[3]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[3]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, LightFilename.c_str(), nullptr, &m_textures[4]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[4]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, DumpFilename.c_str(), nullptr, &m_textures[5]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[5]);
		if (FAILED(result)) return false;
	}

	result = CreateDDSTextureFromFile(device, SpecularFilename.c_str(), nullptr, &m_textures[6]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[6]);
		if (FAILED(result)) return false;
	}

	return true;
}


void TextureClass::Shutdown()
{
	// Release the texture resource.
	if(m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}


	// Release the texutres resource.
	if (m_textures[0])
	{
		m_textures[0]->Release();
		m_textures[0] = 0;
	}
	if (m_textures[1])
	{
		m_textures[1]->Release();
		m_textures[1] = 0;
	}
	return;
}


ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_texture;
}


ID3D11ShaderResourceView** TextureClass::GetTextureArray()
{
	return m_textures;
}