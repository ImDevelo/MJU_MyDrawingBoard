#pragma once
#include <Windows.h>
#include "MyEvent.h"
#include "FrameHader.h"
#include <string>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class Frame 
	:public Container{
public:
	// �⺻ ������
	Frame(std::wstring);
	Frame(std::wstring, int, int);
	// �ɹ��Լ�
	virtual void run();
	virtual bool processMessage(MyEvent e);
	virtual void processButtonEvent(Button*);
	virtual void setFont(int n = 0, COLORREF c = 0); //��Ʈ�� �����մϴ�.
	virtual void repaint();

	
};

HDC GetHDC();