#pragma once
#include "Layout.h"
class GridLayout :
	public Layout
{
public:
	GridLayout(Container*,int); // �׸��� ���̾ƿ�
	virtual void setPlace();

protected:
	int Line = 1;
};

