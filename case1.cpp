#include "gtest/gtest.h"
#include "Test.h"
#include "v.h"
#include "m.h"
#include "log.h"
#include "http.h"
TEST(case1, true)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(case1, sub_sub_11)
{
    int a = sub_sub(4, 3);
    EXPECT_TRUE(a == 1);
}

TEST(main, TestAass)
{
    TestB a;
    int b = a.ass(4);
    std::cout << a.ass(6) << std::endl;
    EXPECT_EQ(b, 1004);
}
TEST(main, TestV)
{
    TestC a;
    int b = a.ass(4);
    a.testV2();
    a.testV();
    std::cout << a.ass(6) << std::endl;
    EXPECT_EQ(b, 1004);
}

TEST(main, TestD)
{
    TestDD e(34, 1, "shixm");
    e.to_String();
    SEX_E_T t = V;
    SEX_E_T t2 = N;
    SEX_E_T t3 = N;
    EXPECT_EQ(t3, t2);
    std::cout << "++++++++++++++" << std::endl;
    EXPECT_EQ(t, 3);
    std::cout << "++++++++++++++" << std::endl;
    EXPECT_EQ(t2, 2);
    std::cout << "++++++++++++++" << std::endl;
    EXPECT_EQ(t != t2, true);
    std::cout << "++++++++++++++" << std::endl;

    TestDD a(34, 1, G_NAME);
    TestDD b(34, 1, G_NAME, SEX_INIT, "BJ");
    TestDD c;
    TestDD *d = new TestDD();
    d->to_String();
    c.to_String();
    b.to_String();
    a.to_String();
    a.setAge(20);
    a.to_String();
    a.done();
    auto x = a.ddd();
    std::cout << x << std::endl;
    EXPECT_EQ(x, 3);
}

TestDD exec(TestDD &d)
{
    return d;
};
//初始化
//赋值
//复制构造
TEST(main, TestDD3CopyCon)
{
    //此方法没有实现.
    // shixmxx()
    //错误	LNK2019	无法解析的外部符号 "int __cdecl shixmxx(void)" (? shixmxx@@YAHXZ)，函数 "private: virtual void __cdecl main_TestDD3CopyCon_Test::TestBody(void)" (? TestBody@main_TestDD3CopyCon_Test@@EEAAXXZ) 中引用了该符号	ConsoleApplication1	D : \codes\ConsoleApplication1\case1.obj	1

    TestDD e(34, 1, "eshixm");
    TestDD d(35, 2, "dshixm");
    e.to_String();
    //复制构造
    std::cout << "++++++++++++++++" << std::endl;
    TestDD e2 = e;
    e2.to_String();
    //赋值操作
    e2 = d;
    e2.to_String();
    //复制构造
    std::cout << "++++++++++++++++" << std::endl;
    TestDD e3 = exec(e2);
    std::cout << "++++++++++++++++" << std::endl;
    //复制构造
    d = exec(e2);
}

//赋值和拷贝构造的区别
// Test t;
// Test t2 = t;  //注意调用的是拷贝构造函数
// Test t3;
// t3 = t;     //注意调用的是赋值函数

TEST(main, FrindClass)
{
    TestDD d(34, 1, "xm");
    TestE e;
    e.d_to_string(d);
    TestF f;
    f.f_to_string(d, 1);
    outFunP(d);
}
TEST(main, glog)
{
    LOG(INFO) << "testcase-main-glog-test";
}
