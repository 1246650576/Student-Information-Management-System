#ifndef __Student_H__
#define __Student_H__
#include<string>
using namespace std;

class Student {
private:
	string name;		      //����
	string number;			  //ѧ��
	string sex;				  //�Ա�
	string PoliticCountenance;//������ò
	string NativePlace;       //����
	string FamilyAddress;     //��ͥסַ
	string PhoneNumber;       //�绰����
	string EMail;             //����
	string date;    //��������
	string age;     //����
	string classes; //�༶

public:
	Student(){};
	~Student(){};
	//��ȡѧ����Ϣ
	string getNumber()const { return number; }
	string getName()const { return name; }
	string getSex()const { return sex; }
	string getPoliticCountenance()const { return PoliticCountenance; }
	string getNativePlace()const { return NativePlace; }
	string getFamilyAddress()const { return FamilyAddress; }
	string getPhoneNumber()const { return PhoneNumber; }
	string getEMail()const { return EMail; }
	string getDate(){ return date; }
	string getAge()const { return age; }
	string getClasses()const { return classes; }

	//����ѧ����Ϣ
	void setNumber(string number) { this->number = number; }
	void setName(string name) { this->name = name; }
	void setSex(string sex) { this->sex = sex; }
	void setPoliticCountenance(string PoliticCountenance) { this->PoliticCountenance = PoliticCountenance; }
	void setNativePlace(string NativePlace) { this->NativePlace = NativePlace; }
	void setFamilyAddress(string FamilyAddress) { this->FamilyAddress = FamilyAddress; }
	void setPhoneNumber(string PhoneNumber) { this->PhoneNumber = PhoneNumber; }
	void setEMail(string EMail) { this->EMail = EMail; }
	void setAge(string age){ this->age = age; }
	void setDate(string date) { this->date = date; }
	void setClasses(string classes) { this->classes = classes; }

	//���������������Ϊ�ǳ�Ա����
	friend ostream& operator<<(ostream& os, Student& student);
	//��������ȡ�����Ϊ�ǳ�Ա����
	friend istream& operator>>(istream& is, Student& student);
};
#endif //__Student_H__
