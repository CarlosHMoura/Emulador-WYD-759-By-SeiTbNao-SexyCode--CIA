#pragma once



class UIControl
{
protected:
	UIControl* MainClass;
	UIControl* pad_0004;
	UIControl* NextWindows;
	UIControl* LastWindow;
public:
	UINT32 Unk_01;
	UINT32 Unk_02;
	UINT32 Unk_03;
	UINT32 Unk_04;
	UINT32 Unk_05;
	UINT32 IsVisible;
	UINT32 Unk_06;
	UINT32 Unk_07;
	UINT32 MouseOver;
	UINT32 TextureID;
	UINT32 Unk_08;
	UINT32 ControlType;
	UINT32 Handle;
	UINT32 Unk_09;
	float Left;
	float Top;
	float Width;
	float Height;
protected:
	UIControl* ReferencedClass; 
public:
	unsigned int ScreenMove; 
	virtual void above(void);

	UIControl* getMainClass()
	{
		if (!this->MainClass)
			return NULL;

		return this->MainClass;
	}

	int getMainHandle()
	{
		if (auto main = this->getMainClass())
			return main->Handle;

		return NULL;
	}

	template<class T> int  addElement(T* Componente)
	{
		return callThiscall(0x005351E9, int, UIControl*, T*)(this, Componente);
	}

	void setHandle(int hand) {
		this->Handle = hand;
	}

	void moveWindow(float X, float Y) {
		this->Left = X;
		this->Top = Y;
	}

	void Show() {
		this->IsVisible != this->IsVisible;
	}

};