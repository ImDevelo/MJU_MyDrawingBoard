#pragma once
#include "MyEvent.h"
class Container;
class Layout
{
public:
	Layout(Container*);  //���̾ƿ�
	virtual void setPlace() = 0;
protected:
	Container* pCtn;
};

