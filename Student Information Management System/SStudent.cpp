#include"SStudent.h"

//���������������Ϊ�ǳ�Ա����
ostream& operator<<(ostream& os, Student& student) {
	os << student.name << endl;
	os << student.number << endl;
	os << student.sex << endl;
	os << student.PoliticCountenance << endl;
	os << student.NativePlace << endl;
	os << student.FamilyAddress << endl;
	os << student.PhoneNumber << endl;
	os << student.EMail << endl;
	os << student.date << endl;
	os << student.age << endl;
	os << student.classes << endl;
	return os;
}

//��������ȡ�����Ϊ�ǳ�Ա����
istream& operator>>(istream& is, Student& student) {
	is >> student.name;
	is >> student.number;
	is >> student.sex;
	is >> student.PoliticCountenance;
	is >> student.NativePlace;
	is >> student.FamilyAddress;
	is >> student.PhoneNumber;
	is >> student.EMail;
	is >> student.date;
	is >> student.age;
	is >> student.classes;
	return is;
}