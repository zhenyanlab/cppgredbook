#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <mysqlx/xdevapi.h>
#include <mysql/jdbc.h>

using namespace std;
using namespace mysqlx;

typedef struct person{
    const char * name;
    int64_t id;
    int     user_id;
    const char *  created;
    const char *  testd;
} person_t;
// vector<person_t> db_p_list;


int get_all_p_list(vector<person_t> * db_p_list){
    int retcode = -1;
    sql::mysql::MySQL_Driver *driver = nullptr;
    // 连接
    sql::Connection *con = nullptr;
    // 数据库操作执行对象
    sql::Statement *state = nullptr;
    // 结果对象
    sql::ResultSet *result = nullptr;

    // 初始化驱动
    driver = sql::mysql::get_mysql_driver_instance();
    if (driver == nullptr)
    {
        cout << "driver is null" << endl;
    }
    // 建立连接
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
    if (con == NULL)
    {
        cout << "conn is null" << endl;
    }
    cout << "connect suceess" << endl;
    // 创建数据库操作执行对象
    state = con->createStatement();
    // use database
    state->execute("use test");

    // 执行查询
    // 查询
    result = state->executeQuery("select * from tt_0 where 1=1");

    // 输出查询
    cout << "id" << "\t\t\t\t" << "name" << "\t\t" << "user_id" << "\t\t" << "created" << endl;
    int i=0;
    while(result->next())
    {
        i++;
        person_t t;
        int64_t id = result->getInt64("id");
        std::string names = result->getString("names");
        int user_id = result->getInt("user_id"); 
        std::string created = result->getString("created");
        std::string names2 = names.c_str();
        t.name = names2.c_str();
        std::cout <<"db-scan:"<<  t.name  << std::endl;
        t.user_id = user_id;
        t.created = created.c_str();
        t.id = id;

     //   snprintf(str,sizeof(str),"%s",source); 		//建议size位传入sizeof(str)，源串中拷贝size－1个字符到目标串中

        // std::string temp_str = std::to_string(i);
        // const char* temp_char = temp_str.c_str();
        // std::string const& cc = std::string("TEST") + std::string(temp_char);
        // char const* url_v = cc.c_str();
        t.testd = "TTT";
        db_p_list->insert(db_p_list->end(), t);
        cout << "struts:" <<(*db_p_list)[0].name << std::endl;
        cout << id << "\t\t" << names << "\t\t" << user_id << "\t\t" << created << endl;

    }

    // 释放对象
    //delete result;
    delete state;
    delete con;
    retcode =0;
    return retcode;
}

TEST(mysqlcase ,init2){

    // vector<person_t> * db_p_list = new vector<person_t>(5);
    vector<person_t>  db_p_list;
    int retcode = -1;
    retcode = get_all_p_list(&db_p_list);
    if (retcode == 0){
        for(int i = 0; i < db_p_list.size();i++){
            std::cout << "=================================" << i <<std::endl;
            person p = db_p_list[i];
            std::string namess = std::string(p.name);
            std::cout  <<"testd:"<<"|"<<p.testd<< "|"  << std::endl;
            // std::cout  <<"|"<< strlen(p.name)<< "|" << namess.length() << strlen(namess.c_str()) << std::endl;
            std::cout <<  p.user_id << "\t\t" << db_p_list[i].id << "\t\t" <<"|"<<namess <<"|"<<  std::endl;
        }

        vector<person_t>::iterator it = db_p_list.begin();  
	    for(; it != db_p_list.end(); ++it)
	    {
	    	cout<<(*it).name<<" ";
    	}

    }

}
TEST(mysqlcase, init){
  try 
  {
    SessionSettings option("127.0.0.1", 3306, "root", "root");  //(host, port, user, password)
    mysqlx::Session sess(option);
    //mysqlx::Schema db= sess.getSchema("test");
    // mysqlx::Table tb = db.getTable("tt_0");
    // tb.insert("names", "user_id")
    // .values("lisi",55)
    // .execute();
  }
 catch (const Error &err)
    {
        cout <<"ERROR: " <<err <<endl;
    }
    catch (std::exception &ex)
    {
        cout <<"STD EXCEPTION: " <<ex.what() <<endl;
    }
    catch (const char *ex)
    {
        cout <<"EXCEPTION: " <<ex <<endl;
    }
    
}