#include "Container.h"
Container::Container() {
	winList_ = new list<MyWindows*>;
}
Container::Container(HDC hdc, std::string str, int w, int h)
	:MyWindows(hdc, str,w,h){
	winList_ = new list<MyWindows*>;
}

bool Container::processMessage(MyEvent e) {  //winlsit�� ���μ����� �ҷ� FALSE TURE�� �Ǵ�
	for (auto list : *winList_) {
		if (list->processMessage(e)) {
			return TRUE;
		}
	} return FALSE;
}

void Container::addWindow(MyWindows* ob){	//������ �߰�
	winList_->push_back(ob);
	ob->setParents(this);
}

void Container::arrangeLayout() {  //���̾ƿ� ����
	if (layout_ != nullptr) {
		layout_->setPlace();
	}
}

void Container::repaint() {        //winlist������ ����մϴ�.
	arrangeLayout();
	for (auto wl = winList_->rbegin(); wl != winList_->rend(); wl++) {
		(*wl)->repaint();
	}
}

/*__ ������ �Լ�, set�Լ� __________________________________________*/
std::list<MyWindows*>* Container::getList(){
	return winList_;
}

void Container::addLayout(Layout* p) {
	layout_ = p;
}