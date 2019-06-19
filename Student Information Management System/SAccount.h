#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<io.h>
#include<sstream>

using namespace std;

//�����˻���
class Account {
public:
	//Ĭ�Ϲ��캯��
	Account();
	//���ι��캯��
	Account(string id, string code);
	//��������
	~Account();
	//�����˻�
	void CreatAccount();
	//�޸�����
	void ChangePassword();
	//��֤�˻���Ϣ
	bool verifyInformation();
	//������Ϣ
	void set_id_code(string id, string code);
	//��ȡ��Ϣ
	string get_id()const { return id; }
	string get_code()const {return code[0];}
private:
	string id;		//�˻�
	string code[2]; //����
	int flag;

	//ɾ���˻�
	void DeleteAccount();
	//�����˺���Ϣ�����ش���
	void save_account();
	//�Ӵ��̽���Ϣ����
	void input_account(string filename);
	//�����������룬��*�Ŵ�������
	void hidePassword(string& password);
	//�����ļ���
	bool find_filename(string filename);
};
#endif // __ACCOUNT_H__
