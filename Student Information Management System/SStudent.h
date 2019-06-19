#ifndef __Student_H__
#define __Student_H__
#include<string>
using namespace std;

class Student {
private:
	string name;		      //姓名
	string number;			  //学号
	string sex;				  //性别
	string PoliticCountenance;//政治面貌
	string NativePlace;       //籍贯
	string FamilyAddress;     //家庭住址
	string PhoneNumber;       //电话号码
	string EMail;             //邮箱
	string date;    //出生年月
	string age;     //年龄
	string classes; //班级

public:
	Student(){};
	~Student(){};
	//获取学生信息
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

	//设置学生信息
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

	//重载流插入运算符为非成员函数
	friend ostream& operator<<(ostream& os, Student& student);
	//重载流提取运算符为非成员函数
	friend istream& operator>>(istream& is, Student& student);
};
#endif //__Student_H__
