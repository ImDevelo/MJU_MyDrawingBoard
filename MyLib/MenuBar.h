#pragma once
#include "Bar.h"
#include "ButtonLib.h"
class MenuBar :
	public Bar
{
public:
	//�ɹ� �Լ�
	MenuBar(HDC);
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows* w); //��ư ��ġ ����
protected:
};