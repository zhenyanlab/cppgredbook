#include "gtest/gtest.h"
#include "Test.h"
#include <folly/init/Init.h>
#include <fmt/format.h>
#include <folly/Range.h>
#include <folly/logging/Init.h>
#include <folly/logging/xlog.h>

FOLLY_INIT_LOGGING_CONFIG(".=WARNING,folly=INFO; default:async=true,sync_level=WARNING");

// void test(){
TEST(folly_test_case, main1)
{
    // XLOG(DBG) << "log messages less than INFO will be ignored before initLogging";
    fmt::print("fasdfasdf");
}

// void test(){
TEST(folly_test_case, main2)
{
     XLOG(DBG) << "log messages less than INFO will be ignored before initLogging";
    fmt::print("fasdfasdf");
}