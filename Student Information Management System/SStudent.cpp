#include"SStudent.h"

//重载流插入运算符为非成员函数
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

//重载流提取运算符为非成员函数
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