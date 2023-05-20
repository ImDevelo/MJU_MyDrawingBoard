#pragma once
#include "Button.h"
class RadioButton :
	public Button
{
public:
	RadioButton(HDC, std::string, int, int);
	RadioButton(HDC, std::string, int, int, COLORREF, COLORREF);
	RadioButton(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);
	virtual void ClickAction();            //Ŭ�� �׼��Դϴ�.
	virtual void repaint();
protected:
	std::string str_;
};

