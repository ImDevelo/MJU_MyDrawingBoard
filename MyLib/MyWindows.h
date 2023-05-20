#pragma once
#include "MyEvent.h"
#include <string>
class Frame;
class ToolBar;
class Button;
class MyWindows
{
public:
	MyWindows();
	MyWindows(HDC, std::string, int, int);
	MyWindows(HDC, std::string, int, int, COLORREF, COLORREF);
	MyWindows(HDC, std::string, int, int, int, int);
	virtual bool processMessage(MyEvent);       // �޼����� ó���մϴ�.
	virtual bool isAccess(MyEvent);             // ������ ������ ó���մϴ�.
	virtual void processButtonEvent(Button* b); // ��ư�� �̺�Ʈ�� ó���մϴ�.
	virtual void repaint() = 0;                 // ����մϴ�.
	virtual void setParents(MyWindows*);        // ���� �����͸� �����մϴ�.
	virtual void movePlace(int, int, int, int); // ��ü�� ��ġ�� �����մϴ�.
	/*__ ������ �Լ�, set�Լ� __________________________________________*/
	virtual int getWidth()const;  virtual int getHight()const;
	virtual int getPointX()const; virtual int getPointY()const;
	virtual void setWidth(int);   virtual void setHight(int);
	virtual void setPointX(int);  virtual void setPointY(int);
	virtual int getState()const;  virtual void setState(int);
	virtual void setTitle(std::string s);
	virtual std::string getTitle() const;
	virtual void setColor(COLORREF, COLORREF);
	virtual void PaintColorB();   virtual void PaintColorA();
	virtual COLORREF getColor();
	virtual void repaintAll();
	virtual HWND getHwnd()const;  virtual HDC getHdc()const;
	virtual void setHwnd(HWND);
	
	
	MyWindows* pressed_ = FALSE;  //��ư Up/Down
protected:
	MyWindows* parents_; //���� ������
	std::string title_;  //�̸�
	int x_, y_;			 //x, y ��ǥ
	int widht_, hight_;  //�ʺ�,����
	int State_ = FALSE;  //����
	COLORREF Pen_color_ = RGB(0,0,0);        //�µθ���
	COLORREF Brush_color_ = RGB(255,255,255);//���λ�
	HPEN oldPen_, newPen_;
	HBRUSH oldBrush_, newBrush_;


	//�ڵ�
	HINSTANCE hInst_;
	HWND hWnd_ = NULL;
	HDC hdc_ = NULL;
};
