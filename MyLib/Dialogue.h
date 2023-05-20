#pragma once
#include "MyWindows.h"
//���̾�α׸� �����̳ʿ� �ֱ�� �������� ��Ұ� �ʹ� ����
class Dialogue :
	public MyWindows
{
public:	
	Dialogue(HDC, std::string, int, int);    //���̾�α��� �⺻ ����
	virtual void UiUpdate();                 //�ʱ� ���̾�α�
	virtual bool processMessage(MyEvent);
	virtual void addWorkButton(Button*);     // �⺻ ��ư�� �߰��մϴ�.
	virtual void DialogueAction();           // ���̾� �α��� �׼��Դϴ�.
	virtual void callDialogue(int,int);      // �ٵ��α׸� ���� ��ġ�� �θ��ϴ�.
	virtual void arrangeDialogue();          // ���̾� �α� ���θ� �����մϴ�.
	virtual void repaint();                  // ����մϴ�.

protected:
	Button* move_bar;      //���̾�α׸� �����϶� ���� �ٴ�.
	Button* off_btn;       //���̾� �α׸� �ݴ� ��ư�̴�. //�⺻ ����
	Button* select_btn[3]; //���, Ȯ��, ����� ����.
	int btn_num;
	int move_action;
	int start_x, start_y;
};