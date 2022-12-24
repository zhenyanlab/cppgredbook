#include "gtest/gtest.h"
#include "Test.h"
#include <folly/init/Init.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <string>
#include <folly/Range.h>
#include <folly/logging/Init.h>
#include <folly/logging/xlog.h>
#include <folly/FBString.h>
#include <vector>
#include <folly/base64.h>
#include  "folly_lib.h"
#include <folly/concurrency/ConcurrentHashMap.h>


FOLLY_INIT_LOGGING_CONFIG(".=WARNING,folly=INFO; default:async=true,sync_level=WARNING");
using namespace folly;
// void test(){
TEST(folly_test_case, main1)
{
    std::vector<int> int_list = {1,2,3,4,5,6};
    std::vector<std::string> str_list = {"1","2","3","4","5","6"};
    fmt::print("std:vector-list{}",int_list);
    fmt::print("std:vector-list{}",str_list);
    fmt::print("{}fasdfasdf{}",int_list,str_list);
}
// void test(){
TEST(folly_test_case, main2)
{
    XLOG(ERR) << "log messages less than INFO will be ignored before initLogging";
    fmt::print("{}\n","fasdfasdf");
    fbstring s5("testetfasodfasdfasdfasdfasdfasdfasdfasdfsdfasdfasd");
    fmt::print("{}\n",s5);
    std::string strs = "ab";
    std::string_view sv = "hello";
    std::cout << tt::ta  << tt::plus()<< std::endl;
    std::cout << tb << plus() << std::endl;
    fmt::print("{}\n",folly::base64Encode(s5));
    test_try(1);
    std::cout << "main2_done" << std::endl;
}

class stu_class{
    public:
    std::string name;
    int age;
    std::array<std::string,20> address;
    public:
    const std::string to_str() const{
        std::string ret="";
        // ret.
        ret=name+"|" + std::to_string(age)+"|";
        return ret;
    }
};

TEST(folly_test_case,main3){
    folly::ConcurrentHashMap<std::string,stu_class> stu_map;
    stu_class s;
    s.name="shixm";
    s.age=35;
    s.address.at(0)="BJ";
    stu_map.insert("1",s);
    for (const auto& st : stu_map) {
        auto stu = st.second;
        fmt::print("{}\n",st.second.name);
        //error c++连着点会出问题,定义一个变量后问题解决.
        //fmt::print("{}:{}",st.first,st.second.to_str());
        //error: passing ‘const stu_class’ as ‘this’ argument discards qualifiers [-fpermissive]
        fmt::print("{}:{}",st.first,stu.to_str());
    }

}