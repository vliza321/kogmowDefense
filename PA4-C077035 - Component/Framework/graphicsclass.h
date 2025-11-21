////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "CameraObject.h"
#include "modelclass.h"
#include "textureshaderclass.h"
#include "inputclass.h"
#include "textclass.h"
#include "lightshaderclass.h"
#include "timerclass.h"
#include "SceneManager.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	enum pointColor
	{
		red,
		green,
		blue,
		white
	};

	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	int a = 0;
private:
	bool Render();
private:

	InputClass* m_Input;

	D3DClass* m_d3d;
	TextureShaderClass* m_textureShader;
	LightShaderClass* m_lightShader;
private:
	SceneSystem* m_sceneManager;
};
#endif