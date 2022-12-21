// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <mcheck.h>
#include <iostream>
#include "Test.h"
#include "gtest/gtest.h"
#include "gflagh.h"
#include <string>
#include "log.h"
TEST(main, true)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
void startTest(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int runall = RUN_ALL_TESTS();
    if (runall == 0)
    {
        std::cout << "testcase->RUN_ALL_TESTS  " << std::endl;
    }
    else
    {
        std::cout << "testcase->NOT_RUN_ALL_TESTS_ERROR = " << std::endl;
    }
}

void openlog()
{
    google::InitGoogleLogging("test");                           //使用glog之前必须先初始化库，仅需执行一次，括号内为程序名
    FLAGS_alsologtostderr = true;                                //是否将日志输出到文件和stderr
    FLAGS_colorlogtostderr = true;                               //是否启用不同颜色显示
    google::SetLogDestination(google::GLOG_INFO, "INFO_");       // INFO级别的日志都存放到logs目录下且前缀为INFO_
    google::SetLogDestination(google::GLOG_WARNING, "WARNING_"); // WARNING级别的日志都存放到logs目录下且前缀为WARNING_
    google::SetLogDestination(google::GLOG_ERROR, "ERROR_");     // ERROR级别的日志都存放到logs目录下且前缀为ERROR_
    google::SetLogDestination(google::GLOG_FATAL, "FATAL_");     // FATAL级别的日志都存放到logs目录下且前缀为FATAL_
    FLAGS_log_dir = " ";
}

void initflag(int argc, char **argv)
{
    const std::string str = "@@@@@@@@@@@@@@@@@@\
        asdfasdf\
        asdfasdf\
        @@\
        ";
    gflags::SetUsageMessage(str);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << "ip = " << FLAGS_ip << std::endl;
    std::cout << "port = " << FLAGS_port << std::endl;
    std::cout << "test = " << FLAGS_test << std::endl;
}

int main(int argc, char **argv)
{
    openlog();
    initflag(argc, argv);

    LOG(INFO) << "main-fun-start----";
    // LOG(WARNING) << "warning";
    // LOG(ERROR) << "error";
    // LOG(FATAL) << "fatal";
    if (FLAGS_test == true)
    {
        startTest(argc, argv);
    }
    else
    {
        std::cout << "test not run" << std::endl;
    }

    google::ShutdownGoogleLogging(); //当要结束glog时必须关闭库，否则会内存溢出
    gflags::ShutDownCommandLineFlags();
    return 0;
}
