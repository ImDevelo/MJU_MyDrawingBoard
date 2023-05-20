#pragma once
#include <Windows.h>
#include "MyEvent.h"
#include <string>

class MyShape
{
public:
	MyShape();
	MyShape(HDC, int, int, int, int);
	virtual void SetArea(int, int, int, int);       //���� ����
	virtual bool isShapeArea(MyEvent);              //���� �������� �Ǵ��մϴ�.
	virtual bool isSelectShape(int, int, int, int); //������ �����մϴ�.
	virtual void MoveShape(int, int, int, int);     //������ �����Դϴ�.
	virtual void setColar(COLORREF, COLORREF, int n = 1); //�������� �����մϴ�.
	virtual void SaveShape(FILE*);                  //������ �����մϴ�.
	virtual MyShape* CapyShape() = 0;               //������ �����մϴ�.
	virtual void repaint() = 0;

	int left_ , top_ , right_ , buttom_ ;       //������ ����
protected:
	int x1_ = 0, x2_ = 0, y1_ = 0, y2_ = 0;     //��ǥ��
	int line_ttick = 1;
	COLORREF Pen_color_;  COLORREF Brush_color_;//����


	HDC hdc_;
	HPEN thePen_;     //����
	HBRUSH theBrush_; //���λ�
};
