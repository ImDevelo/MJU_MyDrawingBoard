#pragma once
#include "MyEvent.h"
#include "MyWindows.h"
#include <string>
class Listener;
class Button
	:public MyWindows
{
public:
	Button(HDC, std::string, int, int);
	Button(HDC, std::string, int, int,int,int);
	Button(HDC, std::string, int, int, COLORREF, COLORREF);
	Button(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);

	virtual bool processMessage(MyEvent);  //�޼����� ó���մϴ�.
	virtual void repaint();
	virtual void ClickAction();             // Ŭ�� �׼��Դϴ�.
	virtual void MouseOn(MyEvent);          // ���콺�� ������ ������ �׼��Դϴ�.
	virtual void setMouseOnColor(COLORREF); // ���콺 �÷������� ���� �����մϴ�.
	virtual bool ButtonState() const;       // ��ư�� ���¸� �����մϴ�.
	virtual void setsts(MyWindows*);
protected:
	HBRUSH mouse_on_brush;  // ���콺 �ø��� ��
	HBRUSH mouse_off_brush; // �ƴҶ� ��
	int on_State;           // ���콺�� �÷������� TRUE
	Listener* listen_;      // ������
	MyWindows* sts;
};