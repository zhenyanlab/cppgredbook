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
    stu_class * next_p;
    std::string name;
    int age;
    std::array<std::string,20> address;
    public:
    const std::string to_str() const{
        std::string ret="";
        // ret.
        ret=name+"|" + std::to_string(age)+"|";
        for(const auto & ad:address ){
            if (!ad.empty()){
                ret+=ad + "#";
            }
        }
        return ret;
    }
};

TEST(folly_test_case,main3){
     folly::ConcurrentHashMap<std::string,stu_class>* stu_map = new folly::ConcurrentHashMap<std::string,stu_class>(50);
    // folly::ConcurrentHashMap<std::string,stu_class> stu_map_z(50);
    // folly::ConcurrentHashMap<std::string,stu_class> * stu_map = &stu_map_z;
    stu_class root;
    stu_class s;
    stu_class s2;
    stu_class s3;
    s.name="shixm";
    s2.name="coco";
    s3.name="bonana";
    root.name="root";

    s.next_p=&s2;
    s2.next_p=&s3;
    // s3.next_p=&root;

    s.age=35;
    s.address.at(0)="BJ";
    s.address.at(1)="DJ";
    s.address.at(2)="HB";
    s.address.at(3)="JND";
    stu_map->insert("ka",s);
    stu_map->insert("kb",s2);
    stu_map->insert("kc",s3);


    for (auto& st : *stu_map) {
        auto stu = st.second;
        //error key string 必须 const
        //auto & stt = const_cast<std::pair<std::string,stu_class> &>(st);
        //auto & stt = const_cast<std::pair<const std::string,stu_class> &>(st);
        // auto & stt = const_cast<std::pair< const std::string,stu_class> &>(st);
        //stu_class *  cur = &stt.second;
        const stu_class *  cur = &st.second;
        while(cur!=NULL){
            fmt::print("next:{}\n",cur->name);
            cur = cur->next_p;
        }
        fmt::print("{}\n",st.second.name);
        //error c++连着点a.b.c会出问题,定义一个变量后问题解决.
        //fmt::print("{}:{}",st.first,st.second.to_str());
        //error: passing ‘const stu_class’ as ‘this’ argument discards qualifiers [-fpermissive]
        fmt::print("{}:{}",st.first,stu.to_str());
        fmt::print("\n+++++++++++++++++++++++++++++++++++++++++\n");
    }

}