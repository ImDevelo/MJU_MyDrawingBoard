#pragma once
#include "Bar.h"
class ToolBar
	:public Bar
{
public:
	//�ɹ� �Լ�
	ToolBar();
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows* w);
};