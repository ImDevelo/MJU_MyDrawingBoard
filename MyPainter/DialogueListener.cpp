#include "DialogueListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
DialogueListener::DialogueListener(MyFrame* f) :m_frame(f) {
}


void DialogueListener::processButtonEvent(MyWindows* w) {
	//��ư�� Ŭ���ѰͿ� ���� ���� �����մϴ�.
	std::string btn_name = w->getTitle();
	if (btn_name == "�����ϱ�") {
		m_frame->saveObject();
	}
	else if (btn_name == "�ҷ�����") {
		m_frame->clearAction();
		m_frame->loadObject();
	}
	m_frame->repaintAll();
}