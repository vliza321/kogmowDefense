////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_

///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define DIRECTINPUT_VERSION 0x0800


/////////////
// LINKING //
/////////////
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


//////////////
// INCLUDES //
//////////////
#include <dinput.h>

////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();
public:
	static InputClass& GetInstance()
	{
		static InputClass instance;
		return instance;
	}

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

	bool IsEscapePressed();
	void GetMouseLocation(int&, int&);

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);
	bool IsKeyUp(unsigned int key);
	bool IsKeyHold(unsigned int key);
	bool IsKey(unsigned int key);
	bool PostFrame();
	DIMOUSESTATE GetCurrMouseState();
	DIMOUSESTATE GetLastMouseState();
private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;

	unsigned char m_keyboardLastState[256];
	unsigned char m_keyboardCurrState[256];
	DIMOUSESTATE m_mouseCurrState;
	DIMOUSESTATE m_mouseLastState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
	bool m_keys[256];
};
#endif