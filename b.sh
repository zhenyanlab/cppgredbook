g++ v.cpp  m.cpp gflagtest.cpp Test.cpp case1.cpp case2.cpp case3.cpp webservercase.cpp listTestcase.cpp comm/util.cpp comm/util2.cpp mfilecase.cpp main.cpp -o a.out -L/usr/x86_64-linux-gnu -L/usr/local/lib  -lgtest -lpthread -lgflags -lglog -lcurl -lboost_thread -lworkflow -I/usr/include -g 
if [ $? -eq 0 ]; then
	./a.out -test=true
else
	echo "build G++ ERROR"
fi
# start test case
#./a.out -test=true
