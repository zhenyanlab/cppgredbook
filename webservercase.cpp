#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"
#include <workflow/WFHttpServer.h>


TEST(main, webservercase) {
    std::cout << "start server" << std::endl;
    WFHttpServer server([](WFHttpTask *task) {
        task->get_resp()->append_output_body("<html>Hello World!</html>\n");
    });

    if (server.start(8989) == 0) {  // start server on port 8888
       // getchar(); // press "Enter" to end.
        server.stop();
         std::cout << "start stop" << std::endl;
    }else{
         std::cout << "start server is fail port Error" << std::endl;
    }


}