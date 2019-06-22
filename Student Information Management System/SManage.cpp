#include"SManage.h"

using namespace std;

Manage::Manage():data(5){
	
}
Manage::~Manage() {

}
//录入信息
void Manage::record() {
	CleanScreen();
	Student student;
	string sstring;
	cout << "请输入学生信息: " << endl << endl;
	cout << "姓名: "; cin >> sstring;
	student.setName(sstring);
	cout << "学号: "; cin >> sstring;
	student.setNumber(sstring);
	cout << "性别: "; cin >> sstring;
	student.setSex(sstring);
	cout << "政治面貌: "; cin >> sstring;
	student.setPoliticCountenance(sstring);
	cout << "籍贯: "; cin >> sstring;
	student.setNativePlace(sstring);
	cout << "家庭住址: "; cin >> sstring;
	student.setFamilyAddress(sstring);
	cout << "电话号码: "; cin >> sstring;
	student.setPhoneNumber(sstring);
	cout << "邮箱: "; cin >> sstring;
	student.setEMail(sstring);
	cout << "年龄: "; cin >> sstring;
	student.setAge(sstring);
	cout << "出生年月(例如:2000.01): "; cin >> sstring;
	student.setDate(sstring);
	cout << "班级: "; cin >> sstring;
	student.setClasses(sstring);
	number_student_multimap.insert(pair<string, Student>(student.getNumber(), student));
	save(student, student.getNumber()); //保存信息到磁盘文件
	cout << endl << "录入信息成功..." << endl;
	PauseScreen();
}

//查询
void Manage::find() throw(runtime_error) {
	int n = 1;
	while (n) {
		find_menu();
	    cin >> n;
		string sstring;
		//定义迭代器，并指向多重映射的起始元素
		multimap<string, Student>::iterator it = number_student_multimap.begin();
		
		bool flag_s = true;//状态量

		if (n >= 1&&n <= 5) {
			cout << "输入要查找的" << information[n - 1] << ":" << endl;
			cin >> sstring;
		}
		switch (n) {
		case 0: cout << "返回上级菜单..."; break;
		case 1: 
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->first) {
					flag_s = false; break;
				}					
			if(flag_s) throw runtime_error("查询信息不存在!"); //所查询信息不存在，抛出异常
			output(it->second);
			break;
		case 2:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getName()) {
					flag_s = false; 
					output(it->second);
				}
			if (flag_s) throw runtime_error("查询信息不存在!");//所查询信息不存在，抛出异常
			break;
		case 3:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getSex()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("查询信息不存在!");//所查询信息不存在，抛出异常
			break;
		case 4:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getDate()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("查询信息不存在!");//所查询信息不存在，抛出异常
			break;
		case 5:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getNativePlace()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("查询信息不存在!");//所查询信息不存在，抛出异常
			break;
		}
	}
}

//操作项
void Manage::operate() {
	int n = 1;
	while (n)
	{
		//操作菜单
		operate_menu();
		cin >> n;
		if (n > 9 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n)
			{
			case 0: cout << "\n返回登录界面"; break;
			case 1: about_menu();	break; //关于
			case 2: record();	    break; //录入
			case 3: browse(number_student_multimap.begin(), number_student_multimap.end());  break; //浏览
			case 4: sorts();        break; //排序
			case 5:
				try {
					find();   break; //查询
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen();break;
				}
			case 6: chart();  break; //统计
			case 7:
				try {
					deletes();break; //删除
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen(); break;
				}
			case 8:
				try { 
				    change(); break; //修改信息
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen(); break;
				}
					
			case 9: ChangePassword(); break;//修改密码
			}
		}
	}
}

//输出到屏幕
void Manage::output(Student& student) {
	CleanScreen();
	cout << "   ------------------------------" << endl;
	cout << "            学生学籍信息" << endl;
	cout << "   ------------------------------" << endl << endl;
	cout<< "姓名: " << student.getName() << endl
		<< "学号: " << student.getNumber() << endl
		<< "性别: " << student.getSex() << endl
		<< "政治面貌: " << student.getPoliticCountenance() << endl
		<< "籍贯: " << student.getNativePlace() << endl
		<< "家庭住址: " << student.getFamilyAddress() << endl
		<< "电话号码: " << student.getPhoneNumber() << endl
		<< "邮箱: " << student.getEMail() << endl
		<< "年龄: " << student.getAge() << endl
		<< "出生年月: " << student.getDate() << endl
		<< "班级: " << student.getClasses()  << endl<<endl;
	PauseScreen();
}

//统计
void Manage::statistic() {
	multimap<string, Student>::iterator it_s = number_student_multimap.begin();//定义迭代器，并指向多重映射的起始元素
	for (it_s; it_s != number_student_multimap.end(); it_s++) {
		//按性别统计人数
		if (data[0].count(it_s->second.getSex()))//判断结点是否出现过
			(data[0].find(it_s->second.getSex())->second)++;
		else
			data[0].insert(pair<string, int>(it_s->second.getSex(), 1));

		//按出生日期统计人数
		if (data[1].count(it_s->second.getDate()))//判断结点是否出现过
			(data[1].find(it_s->second.getDate())->second)++;
		else
			data[1].insert(pair<string, int>(it_s->second.getDate(), 1));

		//按籍贯统计人数
		if (data[2].count(it_s->second.getNativePlace()))//判断结点是否出现过
			(data[2].find(it_s->second.getNativePlace())->second)++;
		else
			data[2].insert(pair<string, int>(it_s->second.getNativePlace(), 1));

		//按班级统计人数
		if (data[3].count(it_s->second.getClasses()))//判断结点是否出现过
			(data[3].find(it_s->second.getClasses())->second)++;
		else
			data[3].insert(pair<string, int>(it_s->second.getClasses(), 1));

		//按政治面貌统计学生人数，按班级统计学生党员、团员人数
		if (data[4].count(it_s->second.getClasses()+ it_s->second.getPoliticCountenance()))//判断结点是否出现过
			(data[4].find(it_s->second.getClasses() + it_s->second.getPoliticCountenance())->second)++;
		else
			data[4].insert(pair<string, int>(it_s->second.getClasses() + it_s->second.getPoliticCountenance(), 1));
	}
}

//统计报表
void Manage::chart() {
	statistic();//统计
	int n = 1;
	while (n) {
		statistic_menu();//统计菜单
		cin >> n;
		if (n > 5 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n)
			{
			case 0: cout << "返回上级菜单";
				//当返回上级菜单时，将(vector)data内的数据清空
				for (int i = 0; i < 5; i++)
					data[i].clear();
				break;
			case 1:
				print(n - 1); break;
			case 2:
				print(n - 1); break;
			case 3:
				print(n - 1); break;
			case 4:
				print(n - 1); break;
			case 5:
				print(n - 1); break;
			}
		}
	}
}

//函数chart的辅助函数，实现打印
void Manage::print(int n) {
	CleanScreen();
	cout << endl
		<< "-----------------------------------\n"
		<< "              统计表\n"
		<< "-----------------------------------\n"
		<< setiosflags(ios_base::left) << setw(20) << information_statictis[n] << setw(6) << "人数" << setw(5) << "占比" << endl;
	for (multimap<string, int>::iterator it = data[n].begin(); it != data[n].end(); it++)
		cout  << setw(20) << it->first << setw(2) << it->second << "人  "
		<< setw(5) << (static_cast<double>(it->second) / static_cast<double>(number_student_multimap.size()))*100 << "%" <<endl;//输出所占比例
	cout << resetiosflags(ios_base::left);//清除格式设置
	PauseScreen();
	cout << endl;
}

//删除学生信息
void Manage::deletes() throw(runtime_error) {
	string filename;//存储要删除的学生学号
	string path;    //存储路径
	
	cout << "输入要删除的学生学号："; cin >> filename;
	//判断所要删除的学号是否存在，不存在则抛出异常
	multimap<string, Student>::iterator it = number_student_multimap.find(filename);
	if (it == number_student_multimap.end()) throw runtime_error("学号不存在!");

	path = ".\\Data output\\" + filename + ".txt";//改成路径
	number_student_multimap.erase(filename);	  //删除键所指的元素
	//删除指定路径下的文件
	DeleteFileA(path.c_str());
	
	cout << "删除成功...";
	PauseScreen();
}

//排序
void Manage::sorts() {
	int n = 1;
	while (n)
	{
		//排序菜单
		sort_menu();
		cin >> n;
		if (n > 2 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n) {
			case 0: cout << "返回上级菜单....\n"; break;
			case 1: sorts_number();	 break;//按学号排序并输出
			case 2:	sorts_date(); break;   //按出生日期排序并输出
			}
		}
		PauseScreen();

	}
}

//按学号进行排序
void Manage::sorts_number() {
	//将multimap中的元素转存到vector中
	vector<PAIR> number_student_vec(number_student_multimap.begin(), number_student_multimap.end());
	//在STL标准容器中只有vector、string、deque可以使用sort
	sort(number_student_vec.begin(), number_student_vec.end(), CmpByKeyNumber());
	//浏览信息
	browse(number_student_vec.begin(), number_student_vec.end());
}

//按出生年月日排序
void Manage::sorts_date() {
	//将multimap中的元素转存到vector中
	vector<PAIR> number_student_vec(number_student_multimap.begin(), number_student_multimap.end());
	//在STL标准容器中只有vector、string、deque可以使用sort
	sort(number_student_vec.begin(), number_student_vec.end(), CmpByValueDate());
	//浏览信息
	browse(number_student_vec.begin(), number_student_vec.end());
}

//修改信息
void Manage::change() throw(runtime_error){
	string filename;//存储要修改的学生学号
	string path;//存储路径
	cout << "输入要修改的学生的学号："; cin >> filename;
	//返回键为filename的映射的迭代器
	multimap<string, Student>::iterator it = number_student_multimap.find(filename);
	//判断所要修改的学号是否存在，不存在则抛出异常
	if (it == number_student_multimap.end()) throw runtime_error("学号不存在!");

	edit(it->second);
	//删除指定路径下的文件
	path = ".\\Data output\\" + filename + ".txt";//改成路径
	DeleteFileA(path.c_str());
	//保存编辑后的文件
	save(it->second, it->second.getNumber());
}

//编辑信息
void Manage::edit(Student& student) {
	int n = 1;
	while (n) {
		edit_menu();//编辑菜单
		string sstring;
	    cin >> n;
		if (n > 10 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n) {
			case 0: cout << "返回主界面..."; break;
			case 1: cout << "姓名:"; cin >> sstring;
				student.setName(sstring);
				break;
			case 2: cout << "性别:"; cin >> sstring;
				student.setSex(sstring);
				break;
			case 3: cout << "政治面貌:"; cin >> sstring;
				student.setPoliticCountenance(sstring);
				break;
			case 4: cout << "籍贯:"; cin >> sstring;
				student.setNativePlace(sstring);
				break;
			case 5: cout << "家庭住址:"; cin >> sstring;
				student.setFamilyAddress(sstring);
				break;
			case 6: cout << "电话号码:"; cin >> sstring;
				student.setPhoneNumber(sstring);
				break;
			case 7: cout << "邮箱:"; cin >> sstring;
				student.setEMail(sstring);
				break;
			case 8: cout << "年龄:"; cin >> sstring;
				student.setAge(sstring);
				break;
			case 9:cout << "出生年月(例如:2000.01):"; cin >> sstring;
				student.setDate(sstring);
				break;
			case 10:cout << "班级:"; cin >> sstring;
				student.setClasses(sstring);
			}
		}
		if (n >= 1 && n <= 10) cout << "修改成功..." << endl;
		PauseScreen();
	}
}