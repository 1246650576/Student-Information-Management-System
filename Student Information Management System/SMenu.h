#ifndef __MENU_H__
#define __MENU_H__
#include"SConsole.h"
#include<iostream>
using namespace std;

class Menu:public Console{
public:
	//���ÿ���̨
	void settingConsole();
	//��¼�˵�
	void sign_in_menu();
	//�����˵�
	void operate_menu();
	//���ڲ˵�
	void about_menu();
	//��ѯ�˵�
	void find_menu();
	//ͳ�Ʋ˵�
	void statistic_menu();
	//����˵�
	void sort_menu();
	//�޸Ĳ˵�
	void edit_menu();
};

#endif	__MENU_H__

