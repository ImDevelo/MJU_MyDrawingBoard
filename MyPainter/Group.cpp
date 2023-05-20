#include "Group.h"
using namespace std;
Group::Group(){
	List_ = new list<MyShape*>; //�ʱ�ȭ
}

void Group::AddGroup(MyShape* ob) {
	SetArea(ob->left_,ob->top_,ob->right_,ob->buttom_);
	List_->push_back(ob);         //����Ʈ�� �߰�
}

void Group::SetArea(int x1, int y1, int x2, int y2) {      //�׷��� ������ �����մϴ�.
	if (List_->empty()) { 
		left_ = x1; top_ = y1; right_ = x2; buttom_ = y2;
	}
	else {
		if (left_ >= x1) { left_ = x1; }
		if (top_ >= y1) { top_ = y1; }
		if (right_ <= x2) { right_ = x2; }
		if (buttom_ <= y2) { buttom_ = y2; }
	}
}

void Group::MoveShape(int x1, int y1, int x2, int y2) { //��ü�� ������ �����Դϴ�.
	MyShape::MoveShape(x1, y1, x2, y2);
	for (auto it : *List_) {
		it->MoveShape(x1, y1, x2, y2);
	}
}

MyShape* Group::CapyShape() {
	Group* temp = new Group;
	for (auto lt : *List_) {
		temp->AddGroup(lt->CapyShape());
	}
	return temp;
}

void Group::SaveShape(FILE* fp) {
	fprintf(fp, "G [\n");   //�� ����
	for (auto it : *List_) {
		it->SaveShape(fp);
	}
	fprintf(fp, "G ]\n");   //�� ����
}


void Group::repaint() { //����մϴ�.
	for (auto it: *List_) {
		it->repaint();
	}
}