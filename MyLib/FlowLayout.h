#pragma once
#include "Layout.h"
#define HOR 0
#define VER 1
class FlowLayout :
	public Layout
{
public:
	FlowLayout(Container*);          //�÷ο� ���̾ƿ�
	FlowLayout(Container*,int);      //����,������������ ����
	FlowLayout(Container*,int, int); //���� ����
	virtual void setPlace();
protected:
	int x_dis, y_dis;       //x,y����
	int arrange_mode = HOR; //HOR�� ����, VER�� ����
};

