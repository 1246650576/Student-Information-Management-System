#ifndef __MANAGE_H__
#define __MANAGE_H__

#include<wtypes.h>
#include<rpcndr.h>
#include"SStudent.h"
#include"SAccount.h"
#include"SMenu.h"
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stdexcept>

using namespace std;

//给pair声明别名
typedef pair<string, Student> PAIR;

//定义函数对象，按出生年月进行比较,递减
struct CmpByValueDate{
	bool operator()(PAIR& lhs, PAIR& rhs) {
		return lhs.second.getDate() > rhs.second.getDate();
	}
};
//定义函数对象，按学号进行比较,递减
struct CmpByKeyNumber{
	bool operator()(PAIR& lhs, PAIR& rhs) {
		return lhs.first > rhs.first;
	}
};

//定义管理类
class Manage: public Menu, public Account
{
public:
	//默认构造函数
	Manage();
	//带参构造函数
	Manage(string id, string code) :Account(id, code) ,data(5){};
	//析构函数
	~Manage();
	//录入信息
	void record();
	//浏览
	template<class T>
	void browse(T it_begin, T it_end);
	//排序
	void sorts();
	//查询
	void find();
	//输出到屏幕
	void output(Student& student);
	//统计报表
	void chart();
	//删除信息
	void deletes();
	//修改
	void change();
	//操作项
	void operate();
	//从磁盘文件导入信息
	template<class T>
	void input(T& x);
	//获取多重映射的引用
	multimap<string, Student>& get_number_student_multimap() { return number_student_multimap;}
protected:
	//保存信息到磁盘文件
	template<class T>
	void save(T& x, string filename);
	//编辑信息
	void edit(Student& student);
	//按出生年月日进行排序
	void sorts_date();
	//按学号进行排序
	void sorts_number();
private:
	multimap<string, Student> number_student_multimap;//定义多重映射，学号--学生信息
	vector<multimap<string, int> > data;              //存储统计数据，类型--数量
	const char *information[5] = { "学号","姓名","性别","出生年月","籍贯",};
	const char *information_statictis[5] = { "性别","出生年月","籍贯","班级","政治面貌" };

	//函数chart的辅助函数，实现打印
	void print(int n);
	//统计
	void statistic();
};

// 保存信息到磁盘文件
template<class T>
void Manage::save(T& x, string filename) {
	string path;
	path = ".\\Data output\\" + filename + ".txt";//改成路径
	ofstream student_os_file;	//文件输出流
	student_os_file.open(path, ios_base::out);    //文件名为filename，打开文件
	student_os_file << x;   //将x所含信息写入文件
	student_os_file.close();//关闭文件
}

//从磁盘文件导入信息
template<class T>
void Manage::input(T& x) {
	long lf_s;
	ifstream student_is_file;//文件输入流
	_finddata_t File;//_finddata_t存储文件各种信息的结构体，io.h中的结构体
	//搜索路径中符合的名称，“.txt”".
	if ((lf_s = _findfirst(".\\Data output\\*.txt", &File)) == -1) //*.txt代表任意后缀为.txt的文件...
		; 
	else {
		do {
			Student student;
			string filename;//文件名
			string path;    //存储文件的路径

			filename = File.name;
			path = ".\\Data output\\" + filename;    //改成路径
			
			student_is_file.open(path, ios_base::in);//文件名为filename，打开文件
			student_is_file >> student;              //将x信息从文件读入

			int i = filename.length() - 4;
			filename.erase(i, 4);   //删除文件后缀“.txt”

			x.insert(pair<string, Student>(filename, student));
			student_is_file.close();//关闭文件
			filename.clear();
			path.clear();
		} while (_findnext(lf_s, &File) == 0);
	}
	_findclose(lf_s);//关闭由FindFirstFile函数创建的一个搜索句柄
}

//浏览
template<class T>
void Manage::browse(T it_begin, T it_end) {
	CleanScreen();//清屏
	SetSize(150, 35);
	cout << endl << endl << "\t\t\t\t\t\t\t          学籍信息表" << endl;
	cout << "  --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setiosflags(ios_base::left) << "  |" << setw(8) << "姓名" << "|" << setw(11) << "学号" << "|" << setw(6) << "性别" << "|"
		<< setw(10) << "政治面貌" << "|" << setw(20) << "籍贯" << "|" << setw(20) << "家庭住址" << "|" << setw(12) << "电话号码" << "|"
		<< setw(18) << "邮箱" << "|" << setw(5) << "年龄" << "|" << setw(10) << "出生年月" << "|" << setw(14) << "班级" << "|" << endl;
	cout << "  |--------|-----------|------|----------|--------------------|--------------------|------------|------------------|-----|----------|--------------|" << endl;

	T it = it_begin;//定义迭代器，并指向多重映射的起始元素

	//输出每个学生的信息
	for (it; it != it_end; ) {
		cout << "  |"
			<< setw(8) << it->second.getName() << "|"
			<< setw(11) << it->second.getNumber() << "|"
			<< setw(6) << it->second.getSex() << "|"
			<< setw(10) << it->second.getPoliticCountenance() << "|"
			<< setw(20) << it->second.getNativePlace() << "|"
			<< setw(20) << it->second.getFamilyAddress() << "|"
			<< setw(12) << it->second.getPhoneNumber() << "|"
			<< setw(18) << it->second.getEMail() << "|"
			<< setw(5) << it->second.getAge() << "|"
			<< setw(10) << it->second.getDate() << "|"
			<< setw(14) << it->second.getClasses() << "|" << endl;
		if (++it != it_end)
			cout << "  |--------|-----------|------|----------|--------------------|--------------------|------------|------------------|-----|----------|--------------|" << endl;
		else
			cout << "  --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << resetiosflags(ios_base::left);//清除格式设置
	PauseScreen();
}

#endif //__MANAGE_H__

