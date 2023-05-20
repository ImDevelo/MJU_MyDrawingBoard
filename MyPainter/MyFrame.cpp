#define _CRT_SECURE_NO_WARNINGS
#include "MyFrame.h"
#include <time.h>
using namespace std;
MyFrame::MyFrame(wstring title): Frame(title){}
MyFrame::MyFrame(wstring title, int x, int y): Frame(title,x,y){}

void MyFrame::run() {
	InterfaceUpdate();   
	Frame::run();
}
//�ʱ� �������̽��� �ҷ��ɴϴ�.
void MyFrame::InterfaceUpdate() {
	Debug("�ʱ�ȭ\n");
	pShape_ = new list<MyShape*>;
	setFont(15, RGB(240, 240, 240));
	setColor(RGB(100, 100, 100),RGB(45, 45, 45)); //��ü �� ����
	COLORREF p = RGB(100, 100, 100);
	COLORREF b = RGB(45, 45, 45);
	/*__���̾�α�__________________________________________________________*/
	Box* dialog = new Box;
	addWindow(dialog);

	DialogueListener* lis_dia = new DialogueListener(this);
	load_dir = new TextPutDialogue(hdc_, "< �ҷ����� >", 400, 200);
	dialog->addWindow(load_dir);
	load_dir->addWorkButton(new TextButton(hdc_, "���", 100, 30, p, b));
	load_dir->addWorkButton(new TextButton(hdc_, "�ҷ�����", 100, 30, p, b, lis_dia));
	load_dir->enterText("���� �۾��� ������ ���� �����˴ϴ�.");
	load_dir->enterText("�ҷ��� ���� �̸��� �Է����ּ���.");
	TextLabel* tl = new TextLabel(hdc_, "", 330, 30, 0);
	tl->setColor(RGB(100, 100, 100), RGB(65, 65, 65));
	load_dir->addTextLabel(tl);

	help_dir = new TextDialogue(hdc_, "< ���� >", 400, 300);
	dialog->addWindow(help_dir);
	help_dir->addWorkButton(new TextButton(hdc_, "Ȯ��", 100, 30));
	help_dir->enterText("���� : ���� -> ����");
	help_dir->enterText("���� : ���� -> ���� ");
	help_dir->enterText("�������� : ������ư ����");
	help_dir->enterText("�� ���� : ����/ä���� -> ��");
	help_dir->enterText("��� ����� : ����� ����");
	help_dir->enterText("����-�ٿ��ֱ� : ctrl + Ŭ�� ");
	help_dir->enterText("���������̵�: shift + Ŭ�� ");

	save_dir = new TextPutDialogue(hdc_, "< �����ϱ� >", 400, 200);
	dialog->addWindow(save_dir);
	save_dir->addWorkButton(new TextButton(hdc_, "���", 100, 30));
	save_dir->addWorkButton(new TextButton(hdc_, "�����ϱ�", 100, 30, p,b, lis_dia));
	save_dir->enterText("�۾� ������ ���� �����մϴ�.");
	save_dir->enterText("������ ���� �̸��� �Է����ּ���.");
	TextLabel* tx = new TextLabel(hdc_, "", 330, 30, 0);
	tx->setColor(RGB(100, 100, 100), RGB(65, 65, 65));
	save_dir->addTextLabel(tx);



	/*__�޴�__________________________________________________________________*/
	MenuBar* pMenu = new MenuBar(hdc_);
	addWindow(pMenu);
	
	MenuListener* lis_menu = new MenuListener(this); //Ÿ�� ������
	Menu* pm1 = new Menu(hdc_, "����", 100, 30, p, b); //���ϸ޴�
	pMenu->addWindow(pm1);
	pm1->addWindow(new TextButton(hdc_, "���� �����", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "����", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "����", 100, 30, p, b, lis_menu));
	pm1->addWindow(new TextButton(hdc_, "����", 100, 30, p, b, lis_menu));

	
	Menu* pMtb = new Menu(hdc_, "����", 100, 30, p, b); //����
	pMenu->addWindow(pMtb);
	TypeListener* lis_tool1 = new TypeListener(this); //Ÿ�� ������
	pMtb->addWindow(new TextButton(hdc_, "��", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "�簢��", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "����", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "��", 100, 30, p, b, lis_tool1));
	pMtb->addWindow(new TextButton(hdc_, "�����", 100, 30, p, b, lis_tool1));

	Menu* pMhelp = new Menu(hdc_, "����", 100, 30, p, b); //����
	pMenu->addWindow(pMhelp);
	pMhelp->addWindow(new TextButton(hdc_, "����", 100, 30, p, b, lis_menu));


	/*__���� ���� _______________________________________________________________*/
	ToolBar* pMTool_ = new ToolBar;
	addWindow(pMTool_);

	TypeListener* lis_tool = new TypeListener(this); //Ÿ�� ������
	Button* t1 = new TextButton(hdc_, "��", 100, 30, p, b, lis_tool);
	Button* t2 = new TextButton(hdc_, "�簢��", 100, 30, p, b, lis_tool);
	Button* t3 = new TextButton(hdc_, "����", 100, 30, p, b, lis_tool);
	Button* t4 = new TextButton(hdc_, "��", 100, 30, p, b, lis_tool);
	Button* t5 = new TextButton(hdc_, "�����", 100, 30, p, b, lis_tool);
	t1->setsts(pm1);
	t2->setsts(pMtb);
	t3->setsts(pMhelp);
	pMTool_->addWindow(t1);
	pMTool_->addWindow(t2);
	pMTool_->addWindow(t3);
	pMTool_->addWindow(t4);
	pMTool_->addWindow(t5);
	
	/*____����____________________________________________________________________*/
	ToolBar* pMcol = new ToolBar;
	addWindow(pMcol);
	Button* pc = new TextButton(hdc_, "����", 70, 30, p, b, lis_tool);
	pMcol->addWindow(pc);
	pbox = new ColorBox(hdc_, "pbox", 30, 30, RGB(0, 0, 0));
	pMcol->addWindow(pbox);
	Button* bc = new TextButton(hdc_, "ä����", 100, 30, p, b, lis_tool);
	pMcol->addWindow(bc);
	bbox = new ColorBox(hdc_, "bbox", 30, 30, RGB(255, 255, 255));
	pMcol->addWindow(bbox);
	pc->setsts(pm1);
	bc->setsts(pMtb);
	pbox->setsts(pm1);

	ValueListener* lis_option = new ValueListener(this);
	pMcol->addWindow(new TextLabel(hdc_, "��", 30, 30));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(0, 0, 0), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 255, 255),lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(237, 28, 36), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 120, 40),lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(255, 245, 0), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(132, 240, 109), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(34, 177, 76), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(0, 162, 232), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(63, 72, 204), lis_option));
	pMcol->addWindow(new ColorBox(hdc_, 30, 30, RGB(163, 73, 164), lis_option));

	pMcol->addWindow(new TextLabel(hdc_, "�β�", 50, 30));
	wide_label = new TextLabel(hdc_, "", 30, 30, 1);
	wide_label->setValue(1);
	pMcol->addWindow(wide_label);
	pMcol->addWindow(new TextButton(hdc_, "��", 30, 30, p, b, lis_option));
	pMcol->addWindow(new TextButton(hdc_, "��", 30, 30, p, b, lis_option));
	
	/*________________________________________________________________________*/
	addLayout(new FlowLayout(this));
	PaintingType = "��";
	arrangeLayout();
	repaintAll();
}

/* ���μ��� */
bool MyFrame::processMessage(MyEvent e) {
	if (!(Frame::processMessage(e)))         //���� �̺�Ʈ�� ó���մϴ�.
	{                                        //����
		switch (e.event_type_) {
		case WM_LBUTTONDOWN:
		{
			startx = e.x_, starty = e.y_;    //��ǥ����

			if (e.isShiftPressed()) {        //����Ʈ-�������� : �̵�
				if (selectShape(e))
					Action = MOVE_ACTION;
			}
			else if (e.isContolPressed()) {  //��Ʈ��-�������� : ����
				if (selectShape(e))
					Action = CAPY_ACTION;
			}
			else if (PaintingType =="��") {
				Pen_line = new Group;
				PenType = TRUE;
			}
		} break;
		case WM_LBUTTONUP:
		{
			if (Action == MOVE_ACTION && e.isShiftPressed()) { 
				MoveAction(e);               //���� �̵�
				repaintAll();
			}
			else if (Action == CAPY_ACTION && e.isContolPressed()) {
				capyAction(e);               //���� ����
			}
			else if (PaintingType == "��") {
				pShape_->push_back(Pen_line);
				PenType = FALSE;
			}
			else {
				drawAction(e);               //�׸��� �׸��ϴ�.
			}
			Action = DRAW_ACTION;
			repaint();
		} break;
		case WM_RBUTTONDOWN:
		{
			startx = e.x_, starty = e.y_;
		} break;
		case WM_RBUTTONUP:
		{
			groupAction(e);                  //���� �׷�ȭ
			repaint();
		} break;
		case WM_MOUSEMOVE:
		{
			if (PenType) {                   //������ �׸��ϴ�.
				MyLine* lin = new MyLine(hdc_, startx, starty, e.x_, e.y_);
				lin->setColar(Pen_color, Brush_color, Line_wid); //������ ���� �����մϴ�.
				Pen_line->AddGroup(lin);
				startx = e.x_, starty = e.y_;
			}
		}break;
		default: 	break;
		}
	}
	return TRUE;
}

/* ������ �����մϴ�. */
bool MyFrame::selectShape(MyEvent e) { 
	list<MyShape*>::iterator it; 
	int state = FALSE;
	for (it = pShape_->begin(); it != pShape_->end(); it++)
	{
		if ((*it)->isShapeArea(e)) {          //������ �����ߴٸ�
			pTemp = it;
			state = TRUE;
		}
	}
	return state;
}

/* ������ �̵��մϴ�. */
void MyFrame::MoveAction(MyEvent e) {
	Debug("Move Shape.\n");
	(*pTemp)->MoveShape(startx, starty, e.x_, e.y_);
}

/* ������ �����մϴ�. */
void MyFrame::capyAction(MyEvent e) {
	Debug("Capy Shape.\n");
	MyShape* capy_shape = (*pTemp)->CapyShape(); //�Ȱ��� ������ �����մϴ�.
	pShape_->push_back(capy_shape);
	capy_shape->MoveShape(startx, starty, e.x_, e.y_);
}

/* ������ �׷�ȭ �մϴ�. */
void MyFrame::groupAction(MyEvent e) {
	int State = FALSE;
	Group* temp_Group = new Group; //�ӽ� �׷� ������
	for (auto shp : *pShape_)
	{
		if (shp->isSelectShape(startx, starty, e.x_, e.y_)) {//���õȵ�����
			State = TRUE;
			temp_Group->AddGroup(shp); //�ӽ� �׷쿡 �ֽ��ϴ�.
		}
	}
	if (State) {   //���� �׷��� ��������ٸ�
		Debug("Grouping Shape\n");
		for (auto gp : *temp_Group->List_) {
			pShape_->remove(gp); //���� �׷쿡 �ִ����� �����մϴ�.
		}
		pShape_->push_back(temp_Group); //�׷��� �߰��մϴ�.
	}
}

/* ������ �׸��ϴ�. */
void MyFrame::drawAction(MyEvent e) { //����Ʈ Ÿ�Կ� ���� �׸��� �����˴ϴ�.
	MyShape* shape;
	if (PaintingType == "") return;
	Debug("Painting.");
	if (PaintingType == "�簢��") {
		Debug(" | �簢��\n");
		shape = new MyRect(hdc_, startx, starty, e.x_, e.y_);
	}
	else if (PaintingType == "����") {
		Debug(" | ����\n");
		shape = new MyLine(hdc_, startx, starty, e.x_, e.y_);
	}
	else if (PaintingType == "��") {
		Debug(" | ��\n");
		shape = new MyCircle(hdc_, startx, starty, e.x_, e.y_);
	}
	pShape_->push_back(shape);  //������ ����Ʈ�� �ְ�
	shape->setColar(Pen_color,Brush_color,Line_wid); //������ ���� �����մϴ�.
}

/* ��� �����մϴ�. */
void MyFrame::clearAction() {
	delete pShape_;               //�����ϰ�
	pShape_ = new list<MyShape*>; //�ٽ� ����Ʈ ����
}

/* ��ư �̺�Ʈ�� ó���մϴ�.
->�����ʸ� ����ϰ� ������ �ݹ��Լ��� ���� �ʿ� ����.  */
void MyFrame::processButtonEvent(Button* pBtn) { 
	//std::string btn_name = pBtn->getTitle();
	/*
	if (btn_name == "�簢��"|| btn_name == "��"|| btn_name == "����"|| btn_name == "��") {
		PaintingType = btn_name;
	}
	
	 if (btn_name == "ä����") {
		ColorType = 0;
	}
	else if (btn_name == "����") {
		ColorType = 1;
	}
	*/
	/*
	if (btn_name == "ColorBox") {
		select_color = pBtn->getColor();
		if (ColorType == 1) { //����
			Pen_color = select_color;
			((ColorBox*)pbox)->setColor(select_color);
		}
		else if((ColorType == 0)) { //ä����
			Brush_color = select_color; 
			((ColorBox*)bbox)->setColor(select_color);
		}
	}
	else if (btn_name == "��") {
		if (Line_wid < 10) {
			Line_wid++;
			wide_label->setValue(Line_wid);
		}
	}
	else if (btn_name == "��") {
		if (Line_wid > 1) {
			Line_wid--;
			wide_label->setValue(Line_wid);
		}
	}
	*/
	/*__ �޴� Ŭ�� ____________________________________________________________*/
	/*
	if (btn_name == "����") {
		save_dir->callDialogue(130, 130);
	}
	
	
	if (btn_name == "�����ϱ�") {
		saveObject();
	}
	
	else if (btn_name == "����") {
		load_dir->callDialogue(150, 150);
	}
	
	
	else if (btn_name == "�ҷ�����") {
		clearAction();
		loadObject();
	}
	
	 
	else if (btn_name == "�����") {
		clearAction();
	}
	
	
	else if (btn_name == "���� �����") {
		clearAction();
	}
	else if (btn_name == "����") {
		exit(1);
	}
	else if (btn_name == "����") {
		help_dir->callDialogue(150, 100);
	}
	*/
	repaintAll();
}

/* �����մϴ�. */
void MyFrame::saveObject() {
	std::string s = save_dir->getTitle();
	save_dir->setTitle("");
	if (s == "") {
		s = "..//save_file/save.txt";
	}
	else {
		s = "..//save_file/" + s + ".txt";
	}

	FILE* fp;
	fp = fopen(s.c_str(), "wt");
	if (fp == NULL)
		throw(1);
	for (auto wl: *pShape_) {
		wl->SaveShape(fp);
	}
	fclose(fp);
}

/* �ҷ��ɴϴ�. */
void MyFrame::loadObject() { //�ҷ�����
	std::string s = load_dir->getTitle();
	load_dir->setTitle("");
	if (s == "") {
		s = "..//save_file/save.txt";
	}
	else {
		s = "..//save_file/" + s + ".txt";
	}
	FILE* fp;
	fp = fopen(s.c_str(), "rt");
	if (fp == NULL)
		throw(1);

	Group* pGr[100];
	int group_side = -1;
	int x1, y1, x2, y2; //��ǥ   
	char type; //�簢�� Ÿ��
	COLORREF p_color,b_color; //�� �ҷ����� �ӽú���
	int line;

	while (feof(fp) == 0) {  //������ ��� ���������� �ε�
		if (!fscanf(fp, "%c ", &type))
			throw(1);
		if (type == 'G') {   //�׷� �ҷ�����
			char ba;
			if (!fscanf(fp, "%c\n", &ba))
				throw(1);
			if (ba == '[') {           // [ �׷� in
				group_side++;
				pGr[group_side] = new Group;
			}
			else if (ba==']') {        // ] �׷� out
				if (group_side == 0) { //�׷��� ����Ʈ�� ������
					pShape_->push_back(pGr[group_side]); 
				}
				else{                  //�׷��� �׷쿡 ������
					pGr[group_side - 1]->AddGroup(pGr[group_side]);
				}
				group_side--;
			}
		}
		else{
			if (!fscanf(fp, "%d %d %d %d %d %d %d\n", &x1, &y1, &x2, &y2, &p_color, &b_color, &line))
				throw(1);
			MyShape* psh;
			if (type == 'R')
				psh = new MyRect(hdc_, x1, y1, x2, y2);
			else if (type == 'C')
				psh = new MyCircle(hdc_, x1, y1, x2, y2);
			else if (type == 'L')
				psh = new MyLine(hdc_, x1, y1, x2, y2);
			else
				break;
			psh->setColar(p_color, b_color,line);  //�׷쿡 �߰�
			if (group_side != -1) {
				pGr[group_side]->AddGroup(psh);
			}
			else {  //����Ʈ�� �߰�
				pShape_->push_back(psh);
			}
		}
	}
}

/* �׸��ϴ�.   */
void MyFrame::repaint() {
	for (auto it : *pShape_) {
		it->repaint();
	}
	Frame::repaint();
}
