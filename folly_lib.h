#pragma once
#include <iostream>
#include <exception>
namespace tt
{
    int ta = -1;
    int plus();
};
namespace
{
    int tb = -2;
    int plus()
    {
        return tt::ta + tb;
    }
}
int tt::plus()
{
    return ta + tb;
}

void test_try(int d)
{
    try
    {
        float c;
        c = 1 / d;
        std::array<int, 100> arr;
        arr[99] = 1;
        //at 用在std::array类而不是 int a [100] 原始数组.
        //at会throw出异常,所以比较安全?
        arr.at(100)=-1;
        arr[1000000000000] = 1;
    }
    //如果不使用引用exception&的时候,捕获的异常会是基类std::exception
    // catch (std::exception e)
    // root Error:std::exception
    catch (std::exception &e)
    {
        std::cout << "root Error:" << e.what() << std::endl;
    }
    std::cout << "test_try_done" << std::endl;
}
