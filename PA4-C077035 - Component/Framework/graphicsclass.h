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
#include "ObjectClass.h"
#include "textclass.h"
#include "lightshaderclass.h"
#include "timerclass.h"

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

	bool Initialize(int, int, HWND, InputClass*,int);
	void Shutdown();
	bool Frame(int, int);
	int a = 0;
private:
	bool Render();
private:
	int timer;
	bool canInput;
	bool isPause;
	int intensity;
	
	pointColor pointLightColor;

	D3DClass* m_D3D;
	InputClass* m_Input;

	TextureShaderClass* m_TextureShader;

	ObjectClass* m_Object;

	LightShaderClass* m_LightShader;

	int SceneCount;
};
#endif