#include "STime.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//获取当前时间
void Time::getTime()
{
	SYSTEMTIME CurrentTime;
	GetLocalTime(&CurrentTime);

	this->hour = CurrentTime.wHour;
	this->minute = CurrentTime.wMinute;
	this->second = CurrentTime.wSecond;
	this->year = CurrentTime.wYear;
	this->month = CurrentTime.wMonth;
	this->day = CurrentTime.wDay;
	this->week = CurrentTime.wDayOfWeek;
}
//显示当前时间
void Time::showTime() {
	const char* WEEK[7] = {"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};
	getTime();
	int ssecond = second;
	do {
		getTime();
		cout << setw(2) << setfill('0') << hour << ":"
			<< setw(2) << minute << ":"
			<< setw(2) << second << setfill(' ')<< endl;
		cout << year << "年" << month << "月" << day << "日" << "   " << WEEK[week - 1] << endl;
		cout << endl << endl << endl << endl << "      欢迎使用学生信息管理系统" << endl << endl
			<< "              启动中..." << endl;

		//延迟
		for (unsigned int i = 0; i < 333911402; i++) {

		}
		CleanScreen(); //清屏

		//设置启动时间为10秒
	} while ((abs(second - ssecond) <= 10 || abs(second - ssecond) >= 50));
}

//定制控制台界面的名称、颜色、尺寸等等
void Time::settingConsole() {
	Console::HideCursor(true);
	Console::SetTitle("Student Information Management System");
	Console::SetColor("5f");
	Console::SetSize(35, 25);
}