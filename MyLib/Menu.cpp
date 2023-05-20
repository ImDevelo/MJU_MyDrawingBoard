#include "Menu.h"
#include "TextButton.h"
#include "VerticalLayout.h"
Menu::Menu(HDC hdc, std::string str, int w, int h)
	:Container(hdc, str, w, h) {
	addLayout(new VerticalLayout(this));          //���� ���̾ƿ�
	mainButton = new TextButton(hdc, str, w, h);  //�ְ� �Ǵ� ���ι�ư ��ġ
	addWindow(mainButton);
}

Menu::Menu(HDC hdc, std::string str, int w, int h,COLORREF p, COLORREF b)
	:Container(hdc, str, w, h) {
	addLayout(new VerticalLayout(this));          //���� ���̾ƿ�
	mainButton = new TextButton(hdc, str, w, h,p,b);  //�ְ� �Ǵ� ���ι�ư ��ġ
	addWindow(mainButton);
}

bool Menu::processMessage(MyEvent e) {
	if (mainButton->processMessage(e) && !State_) { //mainButton�� ���Ȱ� ������â�� �� �����ٸ�
		if (e.event_type_ == WM_LBUTTONUP) {
			State_ = TRUE; //������â ����
		}
		return TRUE;
	}
	else if (State_) { //����â�� ���ȴٸ� �μ� ��ư�� ���μ��� ��ư ����
		if (e.event_type_ == WM_LBUTTONUP) {
			repaintAll();
			State_ = !State_;
		}
		return Container::processMessage(e);
	}
	return FALSE;
}


void Menu::repaint() {
	arrangeLayout();
	mainButton->repaint();
	if (State_) {
		for (auto wl : *winList_) {
			wl->repaint();
		}
	}
}
