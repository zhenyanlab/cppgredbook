#include "gtest/gtest.h"
#include "Test.h"
#include "v.h"
#include "m.h"
#include "log.h"
#include "http.h"

TEST(main, curlhttp) {
    LOG(INFO) << "testcase-main-glog-test";
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if (curl)
    {
        const char* url = "http://www.baidu.com/";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");//POST数据
        CURLcode curlCode = curl_easy_perform(curl);
        if (CURLE_OK != curlCode) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curlCode));
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}