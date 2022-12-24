g++ -std=c++17 folly_test_case.cpp main.cpp -o a.out -L/usr/x86_64-linux-gnu -L/usr/local/lib  -lfolly -lgtest -lpthread -lgflags -lglog -lcurl -lboost_thread -lworkflow -ljsoncpp -lmysqlcppconn8 -lmysqlclient  -lmysqlcppconn -lz -lm -lrt -lssl -lcrypto  -lfmt   -ldouble-conversion   -ldl -liberty  -I/usr/include -g -W
if [ $? -eq 0 ]; then
	./a.out -test=true
else
	echo "build G++ ERROR"
fi
# start test case
# setenv("MALLOC_TRACE", "mtrace.out", 1)
#./a.out -test=true
