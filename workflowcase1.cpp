
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include "workflow/WFTaskFactory.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFHttpServer.h"
#include "workflow/MySQLResult.h"

using namespace protocol;
void timer_callback(WFTimerTask *timer)
{
    printf("timer_callback:Finished. Press enter to end.\n");
}

void nothingcb(WFHttpTask *task)
{
}
std::string mysqlurl = "mysql://root:root@localhost:3306";
int RETRY_MAX = 1;
std::string query = "SELECT * FROM goadmin.`goadmin_menu`";

const MySQLField *const *fields;
std::vector<MySQLCell> arr;

void mysql_callback(WFMySQLTask *task)
{
    SeriesWork *series = series_of(task);
    void *context = series->get_context();
    
    MySQLResponse *resp = task->get_resp();
    MySQLResultCursor cursor(resp);
    do
    {
        if (cursor.get_cursor_status() != MYSQL_STATUS_GET_RESULT &&
            cursor.get_cursor_status() != MYSQL_STATUS_OK)
        {
            break;
        }
        if (cursor.get_cursor_status() == MYSQL_STATUS_GET_RESULT)
        {
            fprintf(stderr, "cursor_status=%d field_count=%u rows_count=%u\n",
                    cursor.get_cursor_status(), cursor.get_field_count(),
                    cursor.get_rows_count());

            // nocopy api
            fields = cursor.fetch_fields();
            for (int i = 0; i < cursor.get_field_count(); i++)
            {
                if (i == 0)
                {
                    fprintf(stderr, "db=%s table=%s\n",
                            fields[i]->get_db().c_str(), fields[i]->get_table().c_str());
                    fprintf(stderr, "  ---------- COLUMNS ----------\n");
                }
                fprintf(stderr, "  name[%s] type[%s]\n",
                        fields[i]->get_name().c_str(),
                        datatype2str(fields[i]->get_data_type()));
            }
            fprintf(stderr, "  _________ COLUMNS END _________\n\n");
        }
        fprintf(stderr, "---------------- RESULT SET ----------------\n");
        while (cursor.fetch_row(arr))
        {
            fprintf(stderr, "  ------------ ROW ------------\n");
            
            // task->get_resp()->append_output_body("mysql-callback");

            for (size_t i = 0; i < arr.size(); i++)
            {
                fprintf(stderr, "  [%s][%s]", fields[i]->get_name().c_str(),
                        datatype2str(arr[i].get_data_type()));
                if (arr[i].is_string())
                {
                    std::string res = arr[i].as_string();
                    if (res.length() == 0)
                        fprintf(stderr, "[\"\"]\n");
                    else
                        fprintf(stderr, "[%s]\n", res.c_str());
                }
                else if (arr[i].is_int())
                {
                    fprintf(stderr, "[%d]\n", arr[i].as_int());
                }
                else if (arr[i].is_ulonglong())
                {
                    fprintf(stderr, "[%llu]\n", arr[i].as_ulonglong());
                }
                else if (arr[i].is_float())
                {
                    const void *ptr;
                    size_t len;
                    int data_type;
                    arr[i].get_cell_nocopy(&ptr, &len, &data_type);
                    size_t pos;
                    for (pos = 0; pos < len; pos++)
                        if (*((const char *)ptr + pos) == '.')
                            break;
                    if (pos != len)
                        pos = len - pos - 1;
                    else
                        pos = 0;
                    fprintf(stderr, "[%.*f]\n", (int)pos, arr[i].as_float());
                }
                else if (arr[i].is_double())
                {
                    const void *ptr;
                    size_t len;
                    int data_type;
                    arr[i].get_cell_nocopy(&ptr, &len, &data_type);
                    size_t pos;
                    for (pos = 0; pos < len; pos++)
                        if (*((const char *)ptr + pos) == '.')
                            break;
                    if (pos != len)
                        pos = len - pos - 1;
                    else
                        pos = 0;
                    fprintf(stderr, "[%.*lf]\n", (int)pos, arr[i].as_double());
                }
                else if (arr[i].is_date())
                {
                    fprintf(stderr, "[%s]\n", arr[i].as_string().c_str());
                }
                else if (arr[i].is_time())
                {
                    fprintf(stderr, "[%s]\n", arr[i].as_string().c_str());
                }
                else if (arr[i].is_datetime())
                {
                    fprintf(stderr, "[%s]\n", arr[i].as_string().c_str());
                }
                else if (arr[i].is_null())
                {
                    fprintf(stderr, "[NULL]\n");
                }
                else
                {
                    std::string res = arr[i].as_binary_string();
                    if (res.length() == 0)
                        fprintf(stderr, "[\"\"]\n");
                    else
                        fprintf(stderr, "[%s]\n", res.c_str());
                }
            }
            fprintf(stderr, "  __________ ROW END __________\n");
        }
			
    } while (cursor.next_result_set());
}
void callback(WFHttpTask *task)
{
    const void *body;
    size_t size;

    if (task->get_resp()->get_parsed_body(&body, &size))
        fwrite(body, 1, size, stdout);

    WFTimerTask *timer = WFTaskFactory::create_timer_task(1000000, timer_callback);
    WFMySQLTask *mysqltask = WFTaskFactory::create_mysql_task(mysqlurl, RETRY_MAX, mysql_callback);
    mysqltask->get_req()->set_query(query);

    series_of(task)->push_back(mysqltask);
    series_of(task)->push_back(timer);
    printf("\ncallback:Wait for 1 second...\n");
}

TEST(workflow2, webservercase2)
{
    WFHttpServer server([](WFHttpTask *task)
                        {

        protocol::HttpRequest  *req = task->get_req();
        protocol::HttpResponse *resp =  task->get_resp();
        long long seq = task->get_task_seq();
        std::cout<< "Task-SEQ:"  << seq << std::endl;
        //--------------------------------------------//
        protocol::HttpHeaderCursor cursor(req);
        std::string name;
        std::string value;
        char buf[8192];
        while (cursor.next(name, value)){
            auto len = snprintf(buf, 8192, "<p>%s: %s</p>", name.c_str(), value.c_str());
            std::cout << len << "|" << buf << std::endl; 
        }
        //--------------------------------------------//
        const void *body;
        size_t size;
        req->get_parsed_body(&body, &size);
        //std::ostringstream oss;//创建一个流
        //std::string ss1 = *static_cast<std::string*>(body);
        //fwrite(body, 1, size, oss);
        std::string strs((char * )body,size);
        //--------------------------------------------//
        std::cout << size << "|"<< strs<< std::endl;
        std::cout << req->get_request_uri() << std::endl;
        //--------------------------------------------//
        std::cout << req->get_method() << std::endl;
        //--------------------------------------------//
        std::cout << req->get_output_body_size() << std::endl;
        //--------------------------------------------//
        std::string outstr = R"({"name":"shixm","age":33})";
        task->get_resp()->append_output_body(outstr);
        //--------------------------------------------//
	    

        resp->set_http_version("HTTP/1.1");
	    resp->set_status_code("200");
	    resp->set_reason_phrase("OK");
	    resp->add_header_pair("Content-Type", "text/html");
	    resp->add_header_pair("Server", "Sogou WFHttpServer");

        //--------------------------------------------//
        //sleep 1000ms
        series_of(task)->push_back(WFTaskFactory::create_timer_task(1000000, nullptr));
        series_of(task)->push_back(WFTaskFactory::create_http_task("http://gitee.com/", 3, 2, callback));
    });

    if (server.start(8888) == 0)
    {              // start server on port 8888
        getchar(); // press "Enter" to end.
        server.stop();
    }
}
