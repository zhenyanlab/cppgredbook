#pragma once
#include <gflags/gflags.h>
#pragma comment(lib, "./lib/gflags_debug.lib")
#pragma comment(lib, "./lib/gflags_nothreads_debug.lib")

DEFINE_string(ip, "no input", "input ip");
DEFINE_int32(port, 8080, "input port");
DEFINE_bool(test, true, "run test");
