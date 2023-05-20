#include "TypeListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
TypeListener::TypeListener(MyFrame* f) :m_frame(f) {
}


void TypeListener::processButtonEvent(MyWindows* w) {
	//��ư�� Ŭ���ѰͿ� ���� Ÿ���� �����մϴ�.
	std::string btn_name = w->getTitle();

	if (btn_name == "�簢��" || btn_name == "��" || btn_name == "����" || btn_name == "��") {
		m_frame->PaintingType = btn_name;
	}
	else if (btn_name == "ä����") {
		m_frame->ColorType = 0;
	}
	else if (btn_name == "����") {
		m_frame->ColorType = 1;
	}
	else if (btn_name == "�����") {
		m_frame->clearAction();
		m_frame->repaintAll();
	}
	m_frame->repaint();
}