#include <iostream>
#include "Frame.h"
#include "MyFrame.h"

int main() {
	try {
		Frame* win = new MyFrame(L"����"); //������ ����
		win->run(); //��Ÿ�� ����
	}
	catch (int n) {
		std::cerr << "Error" << std::endl;
	}
}
