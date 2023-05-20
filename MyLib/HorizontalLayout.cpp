#include "HorizontalLayout.h"
#include "Container.h"
HorizontalLayout::HorizontalLayout(Container* p)
	:Layout(p) {}

void HorizontalLayout::setPlace() { //�ܼ� ��������
	int x = pCtn->getPointX();
	int y = pCtn->getPointY();
	for (auto wl : *pCtn->getList())
	{
		wl->setPointX(x);  wl->setPointY(y);
		x += wl->getWidth();
	}
}