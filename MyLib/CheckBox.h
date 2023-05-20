#pragma once
#include "Button.h"
class CheckBox :
	public Button
{
public:
	CheckBox(HDC, std::string, int, int);
	CheckBox(HDC, std::string, int, int, COLORREF, COLORREF);
	CheckBox(HDC, std::string, int, int, COLORREF, COLORREF, Listener*);
	virtual void ClickAction();            //Ŭ�� �׼��Դϴ�.
	virtual void repaint();
	virtual void isChecked();
	virtual bool ButtonState() const;      //���� ��ư ���¸� �����մϴ�.
protected:
	std::string str_;
	int State = FALSE;   //  TRUE�� üũ & FALSE�� üũ����
};
