#ifndef __MYTIME_H__
#define __MYTIME_H__
#include "SConsole.h"
using namespace std;

//����ʱ����
class Time :public Console
{
public://�ⲿ�ӿ�
	//��ʾ��ǰʱ��
	void showTime();
	//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
	void settingConsole();

protected://������Ա
	int hour;	//ʱ
	int minute;	//��
	int second;	//��
	int year;   //��
	int month;  //��
	int day;    //��
	int week;   //����

private://˽�г�Ա
	//��ȡ��ǰʱ��
	void getTime();
};
#endif __MYTIME_H__