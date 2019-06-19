#ifndef __MENU_H__
#define __MENU_H__
#include"SConsole.h"
#include<iostream>
using namespace std;

class Menu:public Console{
public:
	//设置控制台
	void settingConsole();
	//登录菜单
	void sign_in_menu();
	//操作菜单
	void operate_menu();
	//关于菜单
	void about_menu();
	//查询菜单
	void find_menu();
	//统计菜单
	void statistic_menu();
	//排序菜单
	void sort_menu();
	//修改菜单
	void edit_menu();
};

#endif	__MENU_H__

