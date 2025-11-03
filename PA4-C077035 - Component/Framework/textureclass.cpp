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

	// filename 문자열을 복사 (수정 가능하도록)
	size_t len = wcslen(filename) + 1;
	WCHAR* texturefilename = new WCHAR[len];
	wcscpy_s(texturefilename, len, filename);

	WCHAR* dot = wcsrchr(texturefilename, L'.');
	if (dot != nullptr) {
		*dot = L'\0';
	}

	// 경로 제거
	WCHAR* slash = wcsrchr(texturefilename, L'/');
	texturefilename = (slash) ? slash + 1 : texturefilename;

	std::wstring Texture1Filename = L"./data/" + std::wstring(texturefilename) + L"T1.dds";
	std::wstring Texture2Filename = L"./data/" + std::wstring(texturefilename) + L"T2.dds";
	std::wstring Alpha1Filename = L"./data/" + std::wstring(texturefilename) + L"A1.dds";
	std::wstring Alpha2Filename = L"./data/" + std::wstring(texturefilename) + L"A2.dds";
	std::wstring LightFilename = L"./data/" + std::wstring(texturefilename) + L"L.dds";
	std::wstring BumpFilename = L"./data/" + std::wstring(texturefilename) + L"B.dds";
	std::wstring SpecularFilename = L"./data/" + std::wstring(texturefilename) + L"S.dds";

	// Load texture data from a file by using DDS texture loader.
	result = CreateDDSTextureFromFile(device, Texture1Filename.c_str(), nullptr, &m_textures[0]);
	if (FAILED(result))
	{
		result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[0]);
		if (FAILED(result)) return false;
	}

	if (SUCCEEDED(result))
	{
		result = CreateDDSTextureFromFile(device, Texture2Filename.c_str(), nullptr, &m_textures[1]);
		if (FAILED(result))
		{
			result = CreateDDSTextureFromFile(device, Texture1Filename.c_str(), nullptr, &m_textures[1]);
			if (FAILED(result)) return false;
		}
	}
	else
	{
		result = CreateDDSTextureFromFile(device, Texture2Filename.c_str(), nullptr, &m_textures[1]);
		if (FAILED(result))
		{
			result = CreateDDSTextureFromFile(device, L"./data/Default.dds", nullptr, &m_textures[1]);
			if (FAILED(result)) return false;
		}
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

	result = CreateDDSTextureFromFile(device, BumpFilename.c_str(), nullptr, &m_textures[5]);
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
	for (int i = 0; i < 7; i++)
	{
		if (m_textures[i])
		{
			m_textures[i]->Release();
			m_textures[i] = 0;
		}
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