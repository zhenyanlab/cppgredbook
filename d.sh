g++ mysqlcase.cpp main.cpp -o a.out -L/usr/x86_64-linux-gnu -L/usr/local/lib  -lgtest -lpthread -lgflags -lglog -lcurl -lboost_thread -lworkflow -ljsoncpp -lmysqlcppconn8 -lmysqlclient  -lmysqlcppconn  -lz -lm -lrt -lssl -lcrypto -ldl -I/usr/include -g 
if [ $? -eq 0 ]; then
	./a.out -test=true
else
	echo "build G++ ERROR"
fi
# start test case
# setenv("MALLOC_TRACE", "mtrace.out", 1)
#./a.out -test=true
