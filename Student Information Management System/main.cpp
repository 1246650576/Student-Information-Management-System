#include<iostream>
#include<string>
#include"STime.h"
#include"SManage.h"
using namespace std;

int  main() {
	//�ڵ�ǰmainĿ¼�½���Data output�ļ���
	system("mkdir \"Data output\"");
	system("mkdir \"Password\"");
	//������Ķ���
	Time my_time;
	Manage my_manage;
	bool flag_s;
	//������������
	my_time.settingConsole();
	my_time.showTime();

	//���õ�¼����
	int n = 1;
	while (n)
	{
		//��¼�˵�
		my_manage.sign_in_menu();
		cin >> n;
		if (n > 2 || n < 0) {
			cout << "�������" << endl;
		}
		else {
			switch (n){
			case 0: cout << "\n �˳�\n";		 break;
			case 1: my_manage.CreatAccount();	 break;
			case 2: flag_s = my_manage.verifyInformation();//��֤�˻���Ϣ
					//�����˺���ֱ�ӵ�¼����ϵͳ�������˺���ص�ѧ����Ϣ���뵱ǰ����
					if (flag_s) my_manage.input(my_manage.get_number_student_multimap());
				    my_manage.operate(); break;
			}
		}
	}
	return 0;
}