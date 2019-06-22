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

//定义账户类
class Account {
public:
	//默认构造函数
	Account();
	//带参构造函数
	Account(string id, string code);
	//析构函数
	~Account();
	//创建账户
	void CreatAccount();
	//修改密码
	void ChangePassword();
	//验证账户信息
	bool verifyInformation();
	//设置信息
	void set_id_code(string id, string code);
	//获取信息
	string get_id()const { return id; }
	string get_code()const {return code[0];}
private:
	string id;		//账号
	string code[2]; //密码
	int flag;

	//删除账户
	void DeleteAccount();
	//保存账号信息到本地磁盘
	void save_account();
	//从磁盘将信息读入
	void input_account(string filename);
	//隐藏输入密码，用*号代替密码
	void hidePassword(string& password);
	//查找文件名
	bool find_filename(string filename);
};
#endif // __ACCOUNT_H__
