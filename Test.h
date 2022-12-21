#pragma once
#ifdef _DEBUG
#pragma comment(lib, "./lib/gtest.lib")
#pragma comment(lib, "./lib/gtest_main.lib")
#else
#pragma comment(lib, "./lib/gtest.lib")
#pragma comment(lib, "./lib/gtest_main.lib")
#endif
#include <iostream>
#define G_NAME "workl"
typedef enum sexENUM
{
	INIT = 1,
	N = 2,
	V = 3
} SEX_E_T;
static const enum sexENUM SEX_INIT = INIT;
//不加 static const 会报错。
// enum  sexENUM SEX_INIT_2 = INIT;

class TestA
{
public:
	int ass(int b);
	virtual void testV() = 0;
	virtual void testV2()
	{
	}
};

class TestB : public TestA
{
	virtual void testV()
	{
		std::cout << "testV";
		return;
	}
	// virtual void testV2() {
	//	std::cout << "testV2";
	//	return;
	// }
};

int sub_sub(int a, int b);
int shixmxx();
int inline shixm(int a, int b, int c)
{
	std::cout << "fasdf";
	return 0;
}

class TestD
{
public:
	TestD() : age(0), sex(false), name(""), sexe(){};
	virtual int ddd();
	virtual void ccc() = 0;
	TestD(const TestD &obj)
	{
	}
	TestD(int age, bool sex, std::string name, SEX_E_T sexe)
	{
		this->age = age;
		this->sex = sex;
		this->name = name;
		this->sexe = sexe;
	}
	void to_String()
	{
		std::cout << "TestD:" << this->age << "|" << this->sex << "|" << this->name << "|" << this->sexe << std::endl;
	}
	int setAge(int age)
	{
		this->age = age;
		return this->age;
	}
	//重定义错误，父类存在
	// int age;
protected:
	SEX_E_T sexe;
	int age;
	bool sex;
	std::string name;
	virtual int done() = 0;

private:
	//重定义错误，父类存在
	// int age;
};