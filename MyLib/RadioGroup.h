#pragma once
#include "Bar.h"
class RadioGroup :
	public Bar
{
public:
	RadioGroup();
	virtual void addWindow(Button*);
	virtual void processButtonEvent(Button*); //��ư�� �̺�Ʈ�� ó���մϴ�.
};

