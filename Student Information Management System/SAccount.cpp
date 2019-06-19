#include"SAccount.h"

//默认构造函数
Account::Account() {
	flag = 0;
}
//带参构造函数
Account::Account(string id, string code) {
	this->id = id;
	this->code[0] = code;
	this->code[2] = code;
	this->flag = 0;
};
//析构函数
Account::~Account() {

}
//创建账户
void Account::CreatAccount() {
	flag = 1;
	cout << "欢迎进入学生信息管理系统登录界面..." << endl;
	cout << "请先注册一个账户!" << endl;
	do {
		if (!(code[0] == code[1])) {
			//在重新读入之前清空字符串
			system("CLS");
			cout << "两次输入的密码不同!" << endl << "请重新注册账户..." << endl << endl;
		}
		//string重载了">>"，但重输入流读入的数据并不会覆盖原来字符串，
		//而是添加到原来字符串之后，为此，使用clear函数清空字符串
		id.clear();
		code[0].clear();
		code[1].clear();
		cout << endl;
		cout << "        >>账号:"; cin >> id;
		cout << "        >>密码(6位):"; hidePassword(code[0]);
		cout << "        >>确定密码:";  hidePassword(code[1]);
	} while (!(code[0] == code[1]));
	//将账户信息保存到本地
	save_account();
}

//设置账号和密码
void Account::set_id_code(string id, string code) {
	this->id = id;
	this->code[0] = code;
	this->code[1] = code;
}

//隐藏输入密码，用*号代替密码(支持退格重新输入)
void Account::hidePassword(string& password) {
	char c;
	int count = 0;
	while ((c = _getch()) != '\r') {  //回车
		if (c == 8) { //退格
			if (count == 0) {
				continue;
			}
			putchar('\b');		//回退一格
			putchar(' ');		//输出一个空格将原来的*隐藏
			putchar('\b');		//回退一格等待输入
			password.pop_back();//同时删除密码的尾字符
			count--;
		}
		if ((c >= 'a'&& c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9')) {//密码只能是字母和数字
			putchar('*');
			password += c;
			count++;
		}
	}
	cout << endl;
}

//保存账号信息到本地磁盘
void Account::save_account() {
	string path;
	ofstream account_os_file;	              //文件输出流
	path = ".\\Password\\" + id + ".txt";     //改成路径
	account_os_file.open(path, ios_base::out);//打开文本文件
	account_os_file << id << endl;     //创建账户
	account_os_file << code[0] << endl;//创建密码
	account_os_file << code[1] << endl;//创建二次密码
	account_os_file.close();	       //关闭文本文件
}

//从磁盘将信息读入
void Account::input_account(string filename) {
	string path;
	path = ".\\Password\\" + filename + ".txt";//改成路径
	ifstream account_is_file;                  //文件输入流
	account_is_file.open(path, ios_base::in);  //文件名为filename，打开文件
	//在读入信息前将id,code[0],code[1]清空，防止数据重叠
	id.clear();
	code[0].clear();
	code[1].clear();
	account_is_file >> id >> code[0] >> code[1];//将x信息从文件读入
	account_is_file.close(); //关闭文件
}

//删除账户的本地磁盘和内存信息
void Account::DeleteAccount() {
	//删除指定文件名的文件，包含在fileapi.h文件中
	string path;
	path = ".\\Password\\" + id + ".txt";//改成路径
	//先删除磁盘文件信息
	DeleteFileA(path.c_str());
	//在清空内存信息
	id.clear();
	code[0].clear();
	code[1].clear();
}

//修改密码
void Account::ChangePassword() {
	system("CLS");
	cout << endl << endl;
	//验证账户信息
	verifyInformation();

	//删除账户的本地磁盘和内存信息
	DeleteAccount();
	cout << "--------------------------" << endl;
	//修改账户信息
	do {
		if (!(code[0] == code[1])) {
			//在重新读入之前清空字符串
			system("CLS");
			id.clear();
			code[0].clear();
			code[1].clear();
			cout << "两次输入的密码不同!" << endl << "请重新修改..." << endl << endl;
		}
		cout << "将账号改为:"; cin >> id;
		cout << "将密码改为(6位):";  hidePassword(code[0]);
		cout << "请确定密码(6位):";  hidePassword(code[1]);
	} while (!(code[0] == code[1]));
	cout << "修改成功" << endl;
	system("pause");
	save_account();//将账户信息保存到本地
}

//验证账户信息
bool Account::verifyInformation() {
	string id_temp = id;       //存放原始账号
	string code_temp = code[0];//存放原始密码
	bool FLAG = false;
	//验证账户信息
	do {
		if (!(id_temp == id && code_temp == code[0])) {
			system("CLS");
			cout << endl << "账号或密码不正确！" << endl
				<< "请重新输入..." << endl;
		}
		//string重载了">>"，但重输入流读入的数据并不会覆盖原来字符串，
		//而是添加到原来字符串之后，为此，使用clear函数清空字符串
		id_temp.clear();
		code_temp.clear();
		cout << endl << "        >>账号:"; cin >> id_temp;
		cout << "        >>密码:"; hidePassword(code_temp);
		if ((find_filename(id_temp)) == 0) {//在指定目录下Data output没有找见id_temp
			cout << "账户不存在！请重新注册账户" << endl;
			system("pause");
			break;
		}
		else {//如果找见
			if (flag != 1) {//若是上次注册的账号
				input_account(id_temp);//从磁盘将信息读入
				FLAG = true;
			}
		}
	} while (!(id_temp == id && code_temp == code[0]));
	return FLAG;
}

//查找文件名 
bool Account::find_filename(string filename) {
	bool flag = false;//"没有找到账户!请重新注册账户" 
	string s;
	long lf;
	_finddata_t File;//_finddata_t存储文件各种信息的结构体，io.h中的结构体
	//搜索路径中符合的名称，“.txt”".
	if ((lf = _findfirst(".\\Password\\*.txt", &File)) == -1) //*.txt代表任意后缀为.txt的文件...
		flag = false;//"没有找到账户!请重新注册账户" 
	else {
		do{
			if ((filename+".txt") == File.name) {//filename加上.txt后缀
				flag = true;
				break;
			}
		} while (_findnext(lf, &File) == 0);
	}
	_findclose(lf);//关闭由FindFirstFile函数创建的一个搜索句柄
	return flag;
}