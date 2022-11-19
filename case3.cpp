#include "gtest/gtest.h"
#include "Test.h"
#include <boost/thread/thread.hpp> //包含boost头文件
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

volatile bool isRuning = true;
volatile int sumCount = 0;
class Data{
    public:
        Data(string names){
            this->name = names;
            this->age = 35;
            //this->address=["1","2","3","4","5"];
            this->add2 = new string("test");

            // this->add3 = new vector<string>();
            this->add3.push_back("vector-it0");
            this->add3.push_back("vector-it1");
            this->add4 = new vector<string>;
            this->add4->push_back("add4-1");
            this->add4->push_back("add4-2");
        }
        void to_strings(){
            std::cout << this << "|"<< this->name << "|"<< this->age << "|"<< *(this->add2) << std::endl;
            for (auto it :this->add3){
                  std::cout <<"vector-for"<< this << "|" << it << std::endl;
            }
            for (auto it2 :*(this->add4)){
                  std::cout <<"vector-for-add4"<< this << "|" << it2 << std::endl;
            }
        }
        std::string  name;
        int age;
        std::string address [5];
        std::string * add2;
        vector<string> add3;
        vector<string> * add4;
        
};
void func3(Data ** ppdata){
    Data d("d");
    d.to_strings();
    Data *  pdata1 =new Data("pdata1");
    pdata1->to_strings();
    Data *  pdata2 =&d;
    //*ppdata = (Data * )malloc(100);
    ppdata = &pdata1;
    (*ppdata)->to_strings();
    Data ** ppdata2 = &pdata1;
}
void func1()
{
    Data * pdata = new Data("pdata");
    Data ** ppdata ;
    func3(ppdata);

    std::string key = "AaBbcD";
    std::unordered_map<std::string, std::vector<std::string>> map_;
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    std::cout << key << std::endl;
    //map_.insert()
    std::vector<char> strList;
    strList.push_back('w');
    strList.push_back('W');
    strList.push_back('Q');
    strList.push_back('T');
    strList.push_back(99);
    // strList.push_back(0);
    strList.push_back('0');
    strList.push_back(0);
    // std::transform(strList.begin(), strList.end(), strList.begin(), ::tolower);
    int i = 0;
    for (auto strs : strList)
    {
        std::cout << "tolower" << strs << std::endl;
        // strs = ::tolower(atoi(strs.c_str()));
        strs = ::tolower(strs);
        strList[i] = strs;
        i++;
    }
    for (auto strs : strList)
    {
        char s = strs;
        std::cout << typeid(s).name() << std::endl;
        std::cout << s << std::endl;
    }
    std::cout << "+++++++++++++++" << std::endl;
    char chararray[strList.size()];
    std::cout << strList.size() << std::endl;
    std::cout << sizeof(strList[0]) << std::endl;
    std::cout << &strList[0] << std::endl;
    std::cout << strList.size() * sizeof(strList[0]) << std::endl;
    memcpy(chararray, &strList[0], strList.size() * sizeof(strList[0]));
    for (auto cc : chararray)
    {
        std::cout << cc << std::endl;
    }
    std::cout << "+++++++++++++++" << std::endl;
    string str2 = string(chararray);
    std::cout << str2 << std::endl;
    std::cout << str2.size() << std::endl;

    const char *charss = str2.c_str();
    std::cout << charss << std::endl;



    static int cnt1 = 0;
    while (isRuning)
    {
        sumCount++;
        cout << "func1:" << cnt1++ << endl;
        sleep(1);
    }
}

void func2()
{
    static int cnt2 = 0;
    while (isRuning)
    {
        sumCount++;
        cout << "\tfunc2:" << cnt2++ << endl;
        sleep(2);
    }
}

TEST(main, boostTest) {
    std::cout << "start main thread" << std::endl;
    boost::thread thread1(&func1);
    boost::thread thread2(&func2);
    // system("read");
    sleep(3);
    isRuning = false;

    thread2.join();
    thread1.join();
    cout << "sumCount:" << sumCount << endl;

    cout << "exit" << endl;
}