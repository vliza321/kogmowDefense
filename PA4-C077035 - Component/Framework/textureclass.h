////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <cwchar>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
// Class name: TextureClass
////////////////////////////////////////////////////////////////////////////////
class TextureClass
{
public:
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	bool Initialize(ID3D11Device*, const WCHAR*);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();
	ID3D11ShaderResourceView** GetTextureArray();
private:
	ID3D11ShaderResourceView* m_texture;
	ID3D11ShaderResourceView* m_textures[7] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
};

#endif