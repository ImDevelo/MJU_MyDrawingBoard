#include "MenuListener.h"
#include "MyFrame.h"
#include "MyWindows.h"
MenuListener::MenuListener(MyFrame* f) :m_frame(f) {
}


void MenuListener::processButtonEvent(MyWindows* w) {
	//��ư�� Ŭ���ѰͿ� ���� ���� �����մϴ�.
	std::string btn_name = w->getTitle();

	if (btn_name == "����") {
		m_frame->save_dir->callDialogue(130, 130);
	}
	else if (btn_name == "����") {
		m_frame->load_dir->callDialogue(150, 150);
	}
	else if (btn_name == "���� �����") {
		m_frame->clearAction();
	}
	else if (btn_name == "����") {
		m_frame->help_dir->callDialogue(150, 100);
	}
	else if (btn_name == "����") {
		exit(1);
	}
}