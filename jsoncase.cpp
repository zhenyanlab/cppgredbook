#include "gtest/gtest.h"
#include "Test.h"
#include "json/json.h"
#include <iostream>
#include <memory>
#include <ctime>
#include <thread>
#include <event2/event.h>
#define EXIT_SUCCESS 0
using namespace std;
TEST(jsoncase, p1)
{
    Json::Value root;
    JSONCPP_STRING err;
    std::string rawJson = R"({"a":"b","Age":33})";
    const auto strJsonLen = static_cast<int>(rawJson.length());
    std::cout << rawJson << strJsonLen << std::endl;
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + strJsonLen, &root,
                       &err))
    {
        std::cout << "error" << std::endl;
    }
    const std::string name = root["a"].asString();
    const int age = root["Age"].asInt();

    std::cout << name << std::endl;
    std::cout << age << std::endl;
}
struct T
{
    string *name;
    string name2;
    char *name3;
    char name4[5];
};

void del_new_int(int *i)
{
    delete i;
}
TEST(jsoncase, mem)
{

    auto r = std::make_shared<int>(42); // r指向的int只有一个引用者
    auto b = r;
    std::cout << *b << std::endl;

    // auto tp = make_shared<T>("1","2","4","5");
    auto tp = make_shared<T>();
    std::cout << sizeof(tp) << std::endl;
    std::unique_ptr<int, decltype(del_new_int) *> tpp(new int(5), del_new_int);
    std::cout << "auto ptr:" << *tpp << std::endl;
}
template <class T = int>
class comp
{
public:
    T ccc(T a, T b)
    {
        if (a > b)
        {
            return a;
        }
        else if (a == b)
        {
            return b;
        }
        else
        {
            return b;
        }
    }
};

TEST(jsonCase, template)
{
    comp<string> scomp;
    string a = scomp.ccc("a", "b");
    std::cout << a << std::endl;
    a = scomp.ccc("c", "b");
    std::cout << a << std::endl;
    comp<int> scomp2;
    int c = scomp2.ccc(3, 6);
    std::cout << c << std::endl;
    comp<int> comp3;
    
}
TEST(jsonCase,ctimetest){
    time_t now = time(0);
    std::cout << now << std::endl;

    char* dt = ctime(&now);
    std::cout << dt << std::endl;
    tm *gmtm = gmtime(&now);
    tm * ltime  =  localtime(&now);
    dt = asctime(gmtm);
    std::cout << dt << std::endl;
    std::cout <<"year:" << ltime->tm_year+1900  << "|" <<ltime->tm_mon+1<< std::endl;
}

void runs(int i){
    int j=0;
    while(1){
        j++;
        time_t now = time(0);
        char* dt = ctime(&now);
        std::cout <<"thread"<<i << ":" << dt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (j>=10){
            break;
        }
    }
      std::cout <<"thread"<<i << "done" << std::endl;

}
TEST(jsoncase,stdthread){
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cout <<"main-start:" << dt << std::endl; 
    std::thread tarr [10];
    for(int i=0;i<10;i++){
        tarr[i]=std::thread(runs,i);    
    }
    for(int i=0;i<10;i++){
        tarr[i].join();
    }
    time_t now2 = time(0);
    dt = ctime(&now);
    std::cout <<"main-done:" << now2-now << std::endl;

}

class tt{
    public:
    tt() noexcept = default;
    tt operator<< (const tt & t) const = delete;
    // tt operator<< (const tt & t) const {
    //     std::cout <<"operator-<< is not implemented" << std::endl;
    //     return t;            
    // }
    // tt(tt t) = delete;
    tt( tt& t) = delete;
    tt(const tt& t) = delete;
    tt(const tt&& )=delete;
};
TEST(jsonCase,classInit){
    
    //以下都不能执行
    //tt t;
    //tt ct;
    //t << ct;

    //t << "ct";
    tt t();
    //tt tt(t);
    //tt(tt& t) = delete;
    //tt ttt(&t);
    //tt(tt&& )=delete;
    //tt ttt(std::move(t));
}


//TODO//Allocator（概念）是对访问、寻址、分配、释放、构造和析构策略的封装。


TEST(jsonCase ,libevent)
{
     
}

