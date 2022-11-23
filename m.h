#pragma once
#include "v.h"

class TestE
{
public:
	void d_to_string(TestDD &d);
};

//不支持类的方法函数做友元
class TestF
{
public:
	int f_to_string(TestDD &d, int i);
};
int outFunP(TestDD &d);