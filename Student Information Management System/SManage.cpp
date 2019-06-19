#include"SManage.h"

using namespace std;

Manage::Manage():data(5){
	
}
Manage::~Manage() {

}
//¼����Ϣ
void Manage::record() {
	CleanScreen();
	Student student;
	string sstring;
	cout << "������ѧ����Ϣ: " << endl << endl;
	cout << "����: "; cin >> sstring;
	student.setName(sstring);
	cout << "ѧ��: "; cin >> sstring;
	student.setNumber(sstring);
	cout << "�Ա�: "; cin >> sstring;
	student.setSex(sstring);
	cout << "������ò: "; cin >> sstring;
	student.setPoliticCountenance(sstring);
	cout << "����: "; cin >> sstring;
	student.setNativePlace(sstring);
	cout << "��ͥסַ: "; cin >> sstring;
	student.setFamilyAddress(sstring);
	cout << "�绰����: "; cin >> sstring;
	student.setPhoneNumber(sstring);
	cout << "����: "; cin >> sstring;
	student.setEMail(sstring);
	cout << "����: "; cin >> sstring;
	student.setAge(sstring);
	cout << "��������(����:2000.01): "; cin >> sstring;
	student.setDate(sstring);
	cout << "�༶: "; cin >> sstring;
	student.setClasses(sstring);
	number_student_multimap.insert(pair<string, Student>(student.getNumber(), student));
	save(student, student.getNumber()); //������Ϣ�������ļ�
	cout << endl << "¼����Ϣ�ɹ�..." << endl;
	PauseScreen();
}

//��ѯ
void Manage::find() throw(runtime_error) {
	int n = 1;
	while (n) {
		find_menu();
	    cin >> n;
		string sstring;
		//�������������ָ�����ӳ�����ʼԪ��
		multimap<string, Student>::iterator it = number_student_multimap.begin();
		
		bool flag_s = true;//״̬��

		if (n >= 1&&n <= 5) {
			cout << "����Ҫ���ҵ�" << information[n - 1] << ":" << endl;
			cin >> sstring;
		}
		switch (n) {
		case 0: cout << "�����ϼ��˵�..."; break;
		case 1: 
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->first) {
					flag_s = false; break;
				}					
			if(flag_s) throw runtime_error("��ѯ��Ϣ������!"); //����ѯ��Ϣ�����ڣ��׳��쳣
			output(it->second);
			break;
		case 2:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getName()) {
					flag_s = false; 
					output(it->second);
				}
			if (flag_s) throw runtime_error("��ѯ��Ϣ������!");//����ѯ��Ϣ�����ڣ��׳��쳣
			break;
		case 3:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getSex()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("��ѯ��Ϣ������!");//����ѯ��Ϣ�����ڣ��׳��쳣
			break;
		case 4:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getDate()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("��ѯ��Ϣ������!");//����ѯ��Ϣ�����ڣ��׳��쳣
			break;
		case 5:
			for (it; it != number_student_multimap.end(); it++)
				if (sstring == it->second.getNativePlace()) {
					flag_s = false;
					output(it->second);
				}
			if (flag_s) throw runtime_error("��ѯ��Ϣ������!");//����ѯ��Ϣ�����ڣ��׳��쳣
			break;
		}
	}
}

//������
void Manage::operate() {
	int n = 1;
	while (n)
	{
		//�����˵�
		operate_menu();
		cin >> n;
		if (n > 9 || n < 0) {
			cout << "�������" << endl;
		}
		else {
			switch (n)
			{
			case 0: cout << "\n���ص�¼����"; break;
			case 1: about_menu();	break; //����
			case 2: record();	    break; //¼��
			case 3: browse(number_student_multimap.begin(), number_student_multimap.end());  break; //���
			case 4: sorts();        break; //����
			case 5:
				try {
					find();   break; //��ѯ
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen();break;
				}
			case 6: chart();  break; //ͳ��
			case 7:
				try {
					deletes();break; //ɾ��
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen(); break;
				}
			case 8:
				try { 
				    change(); break; //�޸���Ϣ
				}catch (exception& e) {
					cout << e.what() << endl;
					PauseScreen(); break;
				}
					
			case 9: ChangePassword(); break;//�޸�����
			}
		}
	}
}

//�������Ļ
void Manage::output(Student& student) {
	CleanScreen();
	cout << "   ------------------------------" << endl;
	cout << "            ѧ��ѧ����Ϣ" << endl;
	cout << "   ------------------------------" << endl << endl;
	cout << "����: " << student.getName() << endl
		<< "ѧ��: " << student.getNumber() << endl
		<< "�Ա�: " << student.getSex() << endl
		<< "������ò: " << student.getPoliticCountenance() << endl
		<< "����: " << student.getNativePlace() << endl
		<< "��ͥסַ: " << student.getFamilyAddress() << endl
		<< "�绰����: " << student.getPhoneNumber() << endl
		<< "����: " << student.getEMail() << endl
		<< "����: " << student.getAge() << endl
		<< "��������: " << student.getDate() << endl
		<< "�༶: " << student.getClasses()  << endl<<endl;
	PauseScreen();
}

//ͳ��
void Manage::statistic() {
	multimap<string, Student>::iterator it_s = number_student_multimap.begin();//�������������ָ�����ӳ�����ʼԪ��
	for (it_s; it_s != number_student_multimap.end(); it_s++) {
		//���Ա�ͳ������
		if (data[0].count(it_s->second.getSex()))//�жϽ���Ƿ���ֹ�
			(data[0].find(it_s->second.getSex())->second)++;
		else
			data[0].insert(pair<string, int>(it_s->second.getSex(), 1));

		//����������ͳ������
		if (data[1].count(it_s->second.getDate()))//�жϽ���Ƿ���ֹ�
			(data[1].find(it_s->second.getDate())->second)++;
		else
			data[1].insert(pair<string, int>(it_s->second.getDate(), 1));

		//������ͳ������
		if (data[2].count(it_s->second.getNativePlace()))//�жϽ���Ƿ���ֹ�
			(data[2].find(it_s->second.getNativePlace())->second)++;
		else
			data[2].insert(pair<string, int>(it_s->second.getNativePlace(), 1));

		//���༶ͳ������
		if (data[3].count(it_s->second.getClasses()))//�жϽ���Ƿ���ֹ�
			(data[3].find(it_s->second.getClasses())->second)++;
		else
			data[3].insert(pair<string, int>(it_s->second.getClasses(), 1));

		//��������òͳ��ѧ�����������༶ͳ��ѧ����Ա����Ա����
		if (data[4].count(it_s->second.getClasses()+ it_s->second.getPoliticCountenance()))//�жϽ���Ƿ���ֹ�
			(data[4].find(it_s->second.getClasses() + it_s->second.getPoliticCountenance())->second)++;
		else
			data[4].insert(pair<string, int>(it_s->second.getClasses() + it_s->second.getPoliticCountenance(), 1));
	}
}

//ͳ�Ʊ���
void Manage::chart() {
	statistic();//ͳ��
	int n = 1;
	while (n) {
		statistic_menu();//ͳ�Ʋ˵�
		cin >> n;
		switch (n)
		{
		case 0: cout << "�����ϼ��˵�"; break;
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
		default:
			break;
		}
	}
}

//����chart�ĸ���������ʵ�ִ�ӡ
void Manage::print(int n) {
	for (multimap<string, int>::iterator it = data[n].begin(); it != data[n].end(); it++)
		cout << it->first << ":" << it->second << "��" << endl;
	PauseScreen();
}

//ɾ��ѧ����Ϣ
void Manage::deletes() throw(runtime_error) {
	string filename;//�洢Ҫɾ����ѧ��ѧ��
	string path;    //�洢·��
	
	cout << "����Ҫɾ����ѧ��ѧ�ţ�"; cin >> filename;
	//�ж���Ҫɾ����ѧ���Ƿ���ڣ����������׳��쳣
	multimap<string, Student>::iterator it = number_student_multimap.find(filename);
	if (it == number_student_multimap.end()) throw runtime_error("ѧ�Ų�����!");

	path = ".\\Data output\\" + filename + ".txt";//�ĳ�·��
	number_student_multimap.erase(filename);	  //ɾ������ָ��Ԫ��
	//ɾ��ָ��·���µ��ļ�
	DeleteFileA(path.c_str());
	
	cout << "ɾ���ɹ�...";
	PauseScreen();
}

//����
void Manage::sorts() {
	int n = 1;
	while (n)
	{
		//����˵�
		sort_menu();
		cin >> n;
		if (n > 2 || n < 0) {
			cout << "�������" << endl;
		}
		else {
			switch (n) {
			case 0: cout << "�����ϼ��˵�....\n"; break;
			case 1: sorts_number();	 break;//��ѧ���������
			case 2:	sorts_date(); break;   //�����������������
			}
		}
		PauseScreen();

	}
}

//��ѧ�Ž�������
void Manage::sorts_number() {
	//��multimap�е�Ԫ��ת�浽vector��
	vector<PAIR> number_student_vec(number_student_multimap.begin(), number_student_multimap.end());
	//��STL��׼������ֻ��vector��string��deque����ʹ��sort
	sort(number_student_vec.begin(), number_student_vec.end(), CmpByKeyNumber());
	//�����Ϣ
	browse(number_student_vec.begin(), number_student_vec.end());
}

//����������������
void Manage::sorts_date() {
	//��multimap�е�Ԫ��ת�浽vector��
	vector<PAIR> number_student_vec(number_student_multimap.begin(), number_student_multimap.end());
	//��STL��׼������ֻ��vector��string��deque����ʹ��sort
	sort(number_student_vec.begin(), number_student_vec.end(), CmpByValueDate());
	//�����Ϣ
	browse(number_student_vec.begin(), number_student_vec.end());
}

//�޸���Ϣ
void Manage::change() throw(runtime_error){
	string filename;//�洢Ҫ�޸ĵ�ѧ��ѧ��
	string path;//�洢·��
	cout << "����Ҫ�޸ĵ�ѧ����ѧ�ţ�"; cin >> filename;
	//���ؼ�Ϊfilename��ӳ��ĵ�����
	multimap<string, Student>::iterator it = number_student_multimap.find(filename);
	//�ж���Ҫ�޸ĵ�ѧ���Ƿ���ڣ����������׳��쳣
	if (it == number_student_multimap.end()) throw runtime_error("ѧ�Ų�����!");

	edit(it->second);
	//ɾ��ָ��·���µ��ļ�
	path = ".\\Data output\\" + filename + ".txt";//�ĳ�·��
	DeleteFileA(path.c_str());
	//����༭����ļ�
	save(it->second, it->second.getNumber());
}

//�༭��Ϣ
void Manage::edit(Student& student) {
	int n = 1;
	while (n) {
		edit_menu();//�༭�˵�
		string sstring;
	    cin >> n;
		if (n > 10 || n < 0) {
			cout << "�������" << endl;
		}
		else {
			switch (n) {
			case 0: cout << "����������..."; break;
			case 1: cout << "����:"; cin >> sstring;
				student.setName(sstring);
				break;
			case 2: cout << "�Ա�:"; cin >> sstring;
				student.setSex(sstring);
				break;
			case 3: cout << "������ò:"; cin >> sstring;
				student.setPoliticCountenance(sstring);
				break;
			case 4: cout << "����:"; cin >> sstring;
				student.setNativePlace(sstring);
				break;
			case 5: cout << "��ͥסַ:"; cin >> sstring;
				student.setFamilyAddress(sstring);
				break;
			case 6: cout << "�绰����:"; cin >> sstring;
				student.setPhoneNumber(sstring);
				break;
			case 7: cout << "����:"; cin >> sstring;
				student.setEMail(sstring);
				break;
			case 8: cout << "����:"; cin >> sstring;
				student.setAge(sstring);
				break;
			case 9:cout << "��������(����:2000.01):"; cin >> sstring;
				student.setDate(sstring);
				break;
			case 10:cout << "�༶:"; cin >> sstring;
				student.setClasses(sstring);
			}
		}
		if (n >= 1 && n <= 10) cout << "�޸ĳɹ�..." << endl;
		PauseScreen();
	}
}