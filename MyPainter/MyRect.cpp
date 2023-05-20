#include "MyRect.h"
using namespace std;
MyRect::MyRect(HDC hdc, int l, int r, int t, int b) :MyShape(hdc, l, r, t, b) { }

MyShape* MyRect::CapyShape() {
	MyShape* temp_ = new MyRect(hdc_,x1_,y1_,x2_, y2_);
	temp_->setColar(Pen_color_,Brush_color_,line_ttick);
	return temp_;
}

void MyRect::SaveShape(FILE* fp) {
	fprintf(fp, "%c ", 'R');  //Ÿ������
	MyShape::SaveShape(fp);
}

void MyRect::repaint() {
	HPEN oldPen = (HPEN)SelectObject(hdc_, thePen_);
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc_, theBrush_);
	::Rectangle(hdc_, x1_, y1_, x2_, y2_);
	SelectObject(hdc_, oldPen);
	SelectObject(hdc_, oldbrush);
}


