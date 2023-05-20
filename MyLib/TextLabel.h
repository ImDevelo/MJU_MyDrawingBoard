#pragma once
#include "MyWindows.h"
#define TEXTMODE 0
#define INTMODE 1
#define DOUBLEMODE 2

class TextLabel :
	public MyWindows
{
public:
	TextLabel(HDC, std::string, int, int);  //�⺻ �ؽ�Ʈ ��
	TextLabel(HDC, std::string, int, int, int); //��忡 ���� ��º�ȯ
	virtual bool processMessage(MyEvent);
	virtual void setMode(int);
	virtual void setValue(long long int);
	virtual void setValued(long double);
	virtual long long int getValue()const;
	virtual long double getValued()const;
	virtual void repaint();

protected:
	int Mode_ = 0; //��忡 ���� ��º�ȯ [ 0 ��Ʈ�� | 1 ����  | 2 �Ǽ� ]
	long long int value_;
	long double valued_;
};

