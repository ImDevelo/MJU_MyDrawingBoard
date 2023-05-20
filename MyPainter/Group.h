#pragma once
#include "MyEvent.h"
#include "MyShape.h"
#include <list>
class Group :public MyShape
{
public:
	Group();
	void AddGroup(MyShape*);
	void MoveShape(int, int, int, int);     //������ �����Դϴ�.
	void SetArea(int,int,int,int);          //�׷��� ������ �����մϴ�.
	MyShape* CapyShape();
	void SaveShape(FILE*);
	void repaint();

	std::list<MyShape*>* List_;   //�׷� ����Ʈ�Դϴ�.
};