#include "RadioButton.h"
RadioButton::RadioButton(HDC hdc, std::string str, int w, int h)
	: Button(hdc, str, w, h) {
	str_ = "�� " + str;
}
RadioButton::RadioButton(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b)
	: Button(hdc, str, w, h, p, b) {
	str_ = "�� " + str;
}
RadioButton::RadioButton(HDC hdc, std::string str, int w, int h, COLORREF p, COLORREF b,Listener* lis)
	: Button(hdc, str, w, h, p, b,lis) {
	str_ = "�� " + str;
}

void RadioButton::ClickAction() {
	if (State_ == FALSE)
		State_ = !State_;
}

void RadioButton::repaint() {
	Button::repaint();
	if (State_) str_ = "�� " + title_;
	else str_ = "�� " + title_;
	::TextOutA(hdc_, x_ + (widht_ / 2 - (strlen(str_.c_str()) * 8)), y_ + (hight_ / 2 - 8),
		str_.c_str(), strlen(str_.c_str()));
}