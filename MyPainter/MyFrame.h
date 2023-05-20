#pragma once
#include "Frame.h"
#include "Shapelib.h"
#include "TypeListener.h"
#include "ValueListener.h"
#include "DialogueListener.h"
#include "MenuListener.h"
#include <list>
#include <typeinfo>
#define DRAW_ACTION 0
#define MOVE_ACTION 1
#define CAPY_ACTION 2
using namespace std;
class MyFrame :
	public Frame
{
public:
	//������
	MyFrame(std::wstring);
	MyFrame(std::wstring, int, int);
	/*____�ɹ��Լ�__________________________________________________*/
	virtual void run();
	virtual void InterfaceUpdate();           //�ʱ� �������̽��� ������Ʈ�մϴ�.
	virtual bool processMessage(MyEvent);
	virtual void processButtonEvent(Button*); //��ư �̹�Ʈ�� ó���մϴ�.
	virtual void saveObject();  //����
	virtual void loadObject();  //���ο���
	virtual void repaint();

	int MoveMode =0;
	  /*____Action _________________________________________________*/
	virtual void MoveAction(MyEvent);         //�׸��� �����̴� �׼��Դϴ�.
	virtual bool selectShape(MyEvent);        //������ �����մϴ�.
	virtual void capyAction(MyEvent);         //������ �����ϴ� �׼��Դϴ�.
	virtual void drawAction(MyEvent);         //�׸��� �����մϴ�.
	virtual void groupAction(MyEvent);        //������ �׷�ȭ �մϴ�.
	virtual void clearAction();


	list<MyShape*>* pShape_;
	list<MyShape*>::iterator pTemp; //�ӽ� ������
	Group* Pen_line;
	int startx = 0, starty = 0;
	/*__Type _______________________________________________________*/
	std::string PaintingType;
	std::string file_name;
	int InformState = FALSE;
	int SearchState = FALSE;
	int Action = DRAW_ACTION;
	int ColorType = 0;
	int PenType = FALSE;


	COLORREF select_color = RGB(255, 255, 255); //���� ���õ� �÷�
	COLORREF Pen_color = RGB(0,0,0);            //�� �÷�
	COLORREF Brush_color = RGB(255,255,255);    //�귯�� �÷�
	int Line_wid = 1;
	/* ___��ư______________________________*/
	ColorBox* pbox;  //�� �����÷�
	ColorBox* bbox;  //�귯�� ���� �÷�
	TextLabel* wide_label;

	/* __ �귯�� ���̾� �α�______________________________*/
	TextPutDialogue* load_dir; //�ҷ�����
	TextPutDialogue* save_dir; //����
	TextDialogue* help_dir;    //����
	
	
};
