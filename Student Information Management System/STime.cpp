#include "STime.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//��ȡ��ǰʱ��
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
//��ʾ��ǰʱ��
void Time::showTime() {
	const char* WEEK[7] = {"������","����һ","���ڶ�","������","������","������","������"};
	getTime();
	int ssecond = second;
	do {
		getTime();
		cout << setw(2) << setfill('0') << hour << ":"
			<< setw(2) << minute << ":"
			<< setw(2) << second << setfill(' ')<< endl;
		cout << year << "��" << month << "��" << day << "��" << "   " <<  WEEK[week] << endl;
		cout << endl << endl << endl << endl << "      ��ӭʹ��ѧ����Ϣ����ϵͳ" << endl << endl
			<< "              ������..." << endl;

		//�ӳ�
		for (unsigned int i = 0; i < 333911402; i++) {

		}
		CleanScreen(); //����

		//��������ʱ��Ϊ10��
	} while ((abs(second - ssecond) <= 10 || abs(second - ssecond) >= 50));
}

//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
void Time::settingConsole() {
	Console::HideCursor(true);
	Console::SetTitle("Student Information Management System");
	Console::SetColor("5f");
	Console::SetSize(35, 25);
}