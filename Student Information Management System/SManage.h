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

//��pair��������
typedef pair<string, Student> PAIR;

//���庯�����󣬰��������½��бȽ�,�ݼ�
struct CmpByValueDate{
	bool operator()(PAIR& lhs, PAIR& rhs) {
		return lhs.second.getDate() > rhs.second.getDate();
	}
};
//���庯�����󣬰�ѧ�Ž��бȽ�,�ݼ�
struct CmpByKeyNumber{
	bool operator()(PAIR& lhs, PAIR& rhs) {
		return lhs.first > rhs.first;
	}
};

//���������
class Manage: public Menu, public Account
{
public:
	//Ĭ�Ϲ��캯��
	Manage();
	//���ι��캯��
	Manage(string id, string code) :Account(id, code) ,data(5){};
	//��������
	~Manage();
	//¼����Ϣ
	void record();
	//���
	template<class T>
	void browse(T it_begin, T it_end);
	//����
	void sorts();
	//��ѯ
	void find();
	//�������Ļ
	void output(Student& student);
	//ͳ�Ʊ���
	void chart();
	//ɾ����Ϣ
	void deletes();
	//�޸�
	void change();
	//������
	void operate();
	//�Ӵ����ļ�������Ϣ
	template<class T>
	void input(T& x);
	//��ȡ����ӳ�������
	multimap<string, Student>& get_number_student_multimap() { return number_student_multimap;}
protected:
	//������Ϣ�������ļ�
	template<class T>
	void save(T& x, string filename);
	//�༭��Ϣ
	void edit(Student& student);
	//�����������ս�������
	void sorts_date();
	//��ѧ�Ž�������
	void sorts_number();
private:
	multimap<string, Student> number_student_multimap;//�������ӳ�䣬ѧ��--ѧ����Ϣ
	vector<multimap<string, int> > data;              //�洢ͳ�����ݣ�����--����
	const char *information[5] = { "ѧ��","����","�Ա�","��������","����",};
	
	//����chart�ĸ���������ʵ�ִ�ӡ
	void print(int n);
	//ͳ��
	void statistic();
};

// ������Ϣ�������ļ�
template<class T>
void Manage::save(T& x, string filename) {
	string path;
	path = ".\\Data output\\" + filename + ".txt";//�ĳ�·��
	ofstream student_os_file;	//�ļ������
	student_os_file.open(path, ios_base::out);    //�ļ���Ϊfilename�����ļ�
	student_os_file << x;   //��x������Ϣд���ļ�
	student_os_file.close();//�ر��ļ�
}

//�Ӵ����ļ�������Ϣ
template<class T>
void Manage::input(T& x) {
	long lf_s;
	ifstream student_is_file;//�ļ�������
	_finddata_t File;//_finddata_t�洢�ļ�������Ϣ�Ľṹ�壬io.h�еĽṹ��
	//����·���з��ϵ����ƣ���.txt��".
	if ((lf_s = _findfirst(".\\Data output\\*.txt", &File)) == -1) //*.txt���������׺Ϊ.txt���ļ�...
		; 
	else {
		do {
			Student student;
			string filename;//�ļ���
			string path;    //�洢�ļ���·��

			filename = File.name;
			path = ".\\Data output\\" + filename;    //�ĳ�·��
			
			student_is_file.open(path, ios_base::in);//�ļ���Ϊfilename�����ļ�
			student_is_file >> student;              //��x��Ϣ���ļ�����

			int i = filename.length() - 4;
			filename.erase(i, 4);   //ɾ���ļ���׺��.txt��

			x.insert(pair<string, Student>(filename, student));
			student_is_file.close();//�ر��ļ�
			filename.clear();
			path.clear();
		} while (_findnext(lf_s, &File) == 0);
	}
	_findclose(lf_s);//�ر���FindFirstFile����������һ���������
}

//���
template<class T>
void Manage::browse(T it_begin, T it_end) {
	CleanScreen();//����
	SetSize(150, 35);
	cout << endl << endl << "\t\t\t\t\t\t\t          ѧ����Ϣ��" << endl;
	cout << "  --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setiosflags(ios_base::left) << "  |" << setw(8) << "����" << "|" << setw(11) << "ѧ��" << "|" << setw(6) << "�Ա�" << "|"
		<< setw(10) << "������ò" << "|" << setw(20) << "����" << "|" << setw(20) << "��ͥסַ" << "|" << setw(12) << "�绰����" << "|"
		<< setw(18) << "����" << "|" << setw(5) << "����" << "|" << setw(10) << "��������" << "|" << setw(14) << "�༶" << "|" << endl;
	cout << "  |--------|-----------|------|----------|--------------------|--------------------|------------|------------------|-----|----------|--------------|" << endl;

	T it = it_begin;//�������������ָ�����ӳ�����ʼԪ��

	//���ÿ��ѧ������Ϣ
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
	cout << resetiosflags(ios_base::left);//�����ʽ����
	PauseScreen();
}

#endif //__MANAGE_H__

