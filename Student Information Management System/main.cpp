#include<iostream>
#include<string>
#include"STime.h"
#include"SManage.h"
using namespace std;

int  main() {
	//在当前main目录下建立Data output文件夹
	system("mkdir \"Data output\"");
	system("mkdir \"Password\"");
	//定义类的对象
	Time my_time;
	Manage my_manage;
	bool flag_s;
	//设置启动界面
	my_time.settingConsole();
	my_time.showTime();

	//设置登录界面
	int n = 1;
	while (n)
	{
		//登录菜单
		my_manage.sign_in_menu();
		cin >> n;
		if (n > 2 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n){
			case 0: cout << "\n 退出\n";		 break;
			case 1: my_manage.CreatAccount();	 break;
			case 2: flag_s = my_manage.verifyInformation();//验证账户信息
					//已有账号且直接登录进入系统，将与账号相关的学生信息导入当前程序
					if (flag_s) my_manage.input(my_manage.get_number_student_multimap());
				    my_manage.operate(); break;
			}
		}
	}
	return 0;
}