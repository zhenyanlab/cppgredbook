#pragma once
#include <string>
#include "Test.h"
using namespace std;

class TestC : public TestA
{
public:
	virtual void testV()
	{
		std::cout << "testC->testV";
		return;
	}
	virtual void testV2()
	{
		std::cout << "testV2";
		return;
	}
};

class TestDD : public TestD
{

public:
	//父类初始化指定父类构造函数
	//变量初始化
	TestDD() : address("") {}
	TestDD(const TestDD &obj)
	{
		cout << "Copy Constructor called" << endl;
		this->age = obj.age;
		this->sex = obj.sex;
		this->sexe = obj.sexe;
		this->name = obj.name;
		this->address = obj.address;
	}
	TestDD(int age, bool sex, string name, SEX_E_T sex_t, string address_i) : address(""), TestD(age, sex, name, sex_t)
	{
		cout << "Init5 Constructor called" << endl;
		this->age = age;
		this->sex = sex;
		this->sexe = sex_t;
		this->name = name;
		this->address = address_i;
	}
	TestDD(int age, bool sex, string name) : address("")
	{
		cout << "Init3 Constructor called" << endl;
		this->age = age;
		this->sex = sex;
		this->name = name;
	}
	void to_String()
	{
		std::cout << "TestDD:" << this->age << "|" << this->sex << "|" << this->name << "|" << this->sexe << "|" << this->address << std::endl;
	}
	virtual int done();
	virtual int ddd();
	virtual void ccc();

private:
	friend class TestE;
	friend int outFunP(TestDD &d);
	string address;
	//会报错,不支持的类的方法设置友元.
	// friend void TestF::f_to_string(TestDD& d, int i);
};
