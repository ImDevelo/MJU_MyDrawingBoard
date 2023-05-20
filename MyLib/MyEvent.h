#pragma once
#include <Windows.h>
#include <string>
#define TRUE 1
#define FALSE 0
class MyEvent{
public:
	MyEvent(UINT message, WPARAM wParam, LPARAM lParam);
	//�ɹ��Լ�
	bool isContolPressed(); // Contol Ŭ�� 
	bool isShiftPressed();  // Shift Ŭ��
	bool isMouseEvent();    // Event - ���콺 Ŭ��
	char kepPressed();
	//�ɹ�����
	UINT event_type_;
	WPARAM lParam_;
	LPARAM wParam_;
	int x_, y_;
};

void Debug(int);
void Debug(int, int);
void Debug(int,int,int,int);

void Debug(const char*);
void Debug(int, const char*);
void Debug(const char* ,int, const char*);

std::string Comma(long long int);
std::string Comma(long double);
