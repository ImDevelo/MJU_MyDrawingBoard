#include "Dialogue.h"
#include "Button.h"
#include "TextButton.h"
//���̾�α� 1�� �ϼ�////////////////
Dialogue::Dialogue(HDC hdc, std::string str, int w, int h)
	: MyWindows(hdc,str,w,h) {
	UiUpdate();
}    //���̾�α��� �⺻ ����
void Dialogue::UiUpdate() {
	off_btn = new TextButton(hdc_, "X", x_ + widht_ - 5, y_, 25, 25);
	off_btn->setParents(this);
	move_bar = new TextButton(hdc_, title_, x_, y_, widht_-25, 25);
	move_bar->setParents(this);
}

bool Dialogue::processMessage(MyEvent e) {
	if (!e.isMouseEvent())
		return FALSE;

	/* �̵� _____ */
	if (move_action && e.event_type_ != WM_MOUSEMOVE) { //�ٸ� �����ٸ�  ��
		movePlace(start_x, start_y, e.x_, e.y_);
		move_action = FALSE;
		return TRUE;
	}
	else if (State_ && move_bar->processMessage(e)) { //�ٸ� ��������  ��
		move_action = TRUE;
		start_x = e.x_;  start_y = e.y_;
		return TRUE;
	}
	/* ���̾� �α� �׼� ______________ */
	if (isAccess(e) && State_) {
		int select_b = FALSE;	
		for (int i = 0; i < btn_num;i++) { //���� ���̾�α��� ��ư�� �����ٸ�
			select_b = select_btn[i]->processMessage(e);
			if (select_b == TRUE)
				break;
		}
		if (select_b == FALSE) {  //��� ��ư�� �����ٸ�
			select_b = off_btn->processMessage(e);
		}
		if (select_b && e.event_type_ == WM_LBUTTONUP) { //���̾� �α� ���� 
			State_ = FALSE;
		}
		else { //�ƴ϶�� �׼�
			DialogueAction();
		}
		return TRUE;
	}
	return FALSE;
}

void Dialogue::callDialogue(int x,int y) {  //���� ��ġ�� ���̾� �α� call
	State_ = TRUE;
	x_ = x;   y_ = y;
}

void Dialogue::addWorkButton(Button* w) { // �⺻ ��ư�� �߰��մϴ�.
	select_btn[btn_num++] = w;
	w->setParents(this);
}

void Dialogue::DialogueAction() {  // ���̾� �α��� �׼��Դϴ�.
	//�������
}

void Dialogue::arrangeDialogue() {
	// X��ư ��ġ, bar ��ġ
	off_btn->setPointX(x_ + widht_ - 25);   off_btn->setPointY(y_);
	move_bar->setPointX(x_);  move_bar->setPointY(y_);

	// �۾� ��ư ��ġ
	if (select_btn[0] != nullptr) {
		int y_val = (y_ + hight_ - (select_btn[0]->getHight() + 5));
		int x_val = (x_ + widht_ - (select_btn[0]->getWidth() + 5));
		for (int i = 0; i < btn_num; i++) {
			select_btn[i]->setPointX(x_val);
			select_btn[i]->setPointY(y_val);
			x_val -= (select_btn[i]->getWidth() + 10);
		}
	}
}

void Dialogue::repaint() {                  // ����մϴ�.
	arrangeDialogue();
	if (State_) {
		::Rectangle(hdc_, x_, y_, x_ + widht_, y_ + hight_);
		::TextOutA(hdc_, x_ + 5, y_ + 5, title_.c_str(), strlen(title_.c_str()));
		off_btn->repaint();
		move_bar->repaint();
		for (int i = 0; i < btn_num; i++) {
			select_btn[i]->repaint();
		}
	}
}