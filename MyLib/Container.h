#pragma once
#include "MyWindows.h"
#include "MyEvent.h"
#include "Layout.h"
#include "FlowLayout.h"
#include <list>
using std::list;
class Container
	:public MyWindows
{
public:
	Container();
	Container(HDC, std::string, int, int);
	virtual bool processMessage(MyEvent);
	virtual void addWindow(MyWindows*);  // ������ ��ü�� �����մϴ�.
	virtual void addLayout(Layout*);     // ���̾ƿ� �߰�
	virtual void arrangeLayout();        // ���̾ƿ� ����
	virtual void repaint();              // ����ϴ� repaint�Լ�
	list<MyWindows*>* getList(); //������

protected:
	list<MyWindows*>* winList_;  //������ ����Ʈ
	Layout* layout_ = nullptr;
};