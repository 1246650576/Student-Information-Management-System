#include"SAccount.h"

//Ĭ�Ϲ��캯��
Account::Account() {
	flag = 0;
}
//���ι��캯��
Account::Account(string id, string code) {
	this->id = id;
	this->code[0] = code;
	this->code[2] = code;
	this->flag = 0;
};
//��������
Account::~Account() {

}
//�����˻�
void Account::CreatAccount() {
	flag = 1;
	cout << "��ӭ����ѧ����Ϣ����ϵͳ��¼����..." << endl;
	cout << "����ע��һ���˻�!" << endl<<endl;
	do {
		if (!(code[0] == code[1])) {
			//�����¶���֮ǰ����ַ���
			system("CLS");
			cout << "������������벻ͬ!" << endl << "������ע���˻�..." << endl << endl;
		}
		//string������">>"��������������������ݲ����Ḳ��ԭ���ַ�����
		//������ӵ�ԭ���ַ���֮��Ϊ�ˣ�ʹ��clear��������ַ���
		id.clear();
		code[0].clear();
		code[1].clear();
		cout << "<������ʾ>1.����ֻ�ܰ������ֺ���ĸ" << endl << "          2.��ĸ���ִ�Сд" << endl;
		cout << "        >>�˺�:"; cin >> id;
		cout << "        >>����(6λ):"; hidePassword(code[0]);
		cout << "        >>ȷ������:";  hidePassword(code[1]);
	} while (!(code[0] == code[1]));
	//���˻���Ϣ���浽����
	save_account();
}

//�����˺ź�����
void Account::set_id_code(string id, string code) {
	this->id = id;
	this->code[0] = code;
	this->code[1] = code;
}

//�����������룬��*�Ŵ�������(֧���˸���������)
void Account::hidePassword(string& password) {
	char c;
	int count = 0;
	while ((c = _getch()) != '\r') {  //�س�
		if (c == 8) { //�˸�
			if (count == 0) {
				continue;
			}
			putchar('\b');		//����һ��
			putchar(' ');		//���һ���ո�ԭ����*����
			putchar('\b');		//����һ��ȴ�����
			password.pop_back();//ͬʱɾ�������β�ַ�
			count--;
		}
		if ((c >= 'a'&& c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9')) {//����ֻ������ĸ������
			putchar('*');
			password += c;
			count++;
		}
	}
	cout << endl;
}

//�����˺���Ϣ�����ش���
void Account::save_account() {
	string path;
	ofstream account_os_file;	              //�ļ������
	path = ".\\Password\\" + id + ".txt";     //�ĳ�·��
	account_os_file.open(path, ios_base::out);//���ı��ļ�
	account_os_file << id << endl;     //�����˻�
	account_os_file << code[0] << endl;//��������
	account_os_file << code[1] << endl;//������������
	account_os_file.close();	       //�ر��ı��ļ�
}

//�Ӵ��̽���Ϣ����
void Account::input_account(string filename) {
	string path;
	path = ".\\Password\\" + filename + ".txt";//�ĳ�·��
	ifstream account_is_file;                  //�ļ�������
	account_is_file.open(path, ios_base::in);  //�ļ���Ϊfilename�����ļ�
	//�ڶ�����Ϣǰ��id,code[0],code[1]��գ���ֹ�����ص�
	id.clear();
	code[0].clear();
	code[1].clear();
	account_is_file >> id >> code[0] >> code[1];//��x��Ϣ���ļ�����
	account_is_file.close(); //�ر��ļ�
}

//ɾ���˻��ı��ش��̺��ڴ���Ϣ
void Account::DeleteAccount() {
	//ɾ��ָ���ļ������ļ���������fileapi.h�ļ���
	string path;
	path = ".\\Password\\" + id + ".txt";//�ĳ�·��
	//��ɾ�������ļ���Ϣ
	DeleteFileA(path.c_str());
	//������ڴ���Ϣ
	id.clear();
	code[0].clear();
	code[1].clear();
}

//�޸�����
void Account::ChangePassword() {
	system("CLS");
	cout << endl << endl;
	//��֤�˻���Ϣ
	verifyInformation();

	//ɾ���˻��ı��ش��̺��ڴ���Ϣ
	DeleteAccount();
	cout << "--------------------------" << endl;
	//�޸��˻���Ϣ
	do {
		if (!(code[0] == code[1])) {
			//�����¶���֮ǰ����ַ���
			system("CLS");
			id.clear();
			code[0].clear();
			code[1].clear();
			cout << "������������벻ͬ!" << endl << "�������޸�..." << endl << endl;
		}
		cout << "���˺Ÿ�Ϊ:"; cin >> id;
		cout << "�������Ϊ(6λ):";  hidePassword(code[0]);
		cout << "��ȷ������(6λ):";  hidePassword(code[1]);
	} while (!(code[0] == code[1]));
	cout << "�޸ĳɹ�" << endl;
	system("pause");
	save_account();//���˻���Ϣ���浽����
}

//��֤�˻���Ϣ
bool Account::verifyInformation() {
	string id_temp = id;       //���ԭʼ�˺�
	string code_temp = code[0];//���ԭʼ����
	bool FLAG = false;
	//��֤�˻���Ϣ
	do {
		if (!(id_temp == id && code_temp == code[0])) {
			system("CLS");
			cout << endl << "�˺Ż����벻��ȷ��" << endl
				<< "����������..." << endl;
		}
		//string������">>"��������������������ݲ����Ḳ��ԭ���ַ�����
		//������ӵ�ԭ���ַ���֮��Ϊ�ˣ�ʹ��clear��������ַ���
		id_temp.clear();
		code_temp.clear();
		cout << endl << "        >>�˺�:"; cin >> id_temp;
		cout << "        >>����:"; hidePassword(code_temp);
		if ((find_filename(id_temp)) == 0) {//��ָ��Ŀ¼��Data outputû���Ҽ�id_temp
			cout << "�˻������ڣ�������ע���˻�" << endl;
			system("pause");
			break;
		}
		else {//����Ҽ�
			if (flag != 1) {//�����ϴ�ע����˺�
				input_account(id_temp);//�Ӵ��̽���Ϣ����
				FLAG = true;
			}
		}
	} while (!(id_temp == id && code_temp == code[0]));
	return FLAG;
}

//�����ļ��� 
bool Account::find_filename(string filename) {
	bool flag = false;//"û���ҵ��˻�!������ע���˻�" 
	string s;
	long lf;
	_finddata_t File;//_finddata_t�洢�ļ�������Ϣ�Ľṹ�壬io.h�еĽṹ��
	//����·���з��ϵ����ƣ���.txt��".
	if ((lf = _findfirst(".\\Password\\*.txt", &File)) == -1) //*.txt���������׺Ϊ.txt���ļ�...
		flag = false;//"û���ҵ��˻�!������ע���˻�" 
	else {
		do{
			if ((filename+".txt") == File.name) {//filename����.txt��׺
				flag = true;
				break;
			}
		} while (_findnext(lf, &File) == 0);
	}
	_findclose(lf);//�ر���_findfirst����������һ���������
	return flag;
}