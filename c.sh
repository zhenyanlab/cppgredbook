g++ v.cpp  jsoncase.cpp case2.cpp workflowcase1.cpp main.cpp -o a.out -L/usr/x86_64-linux-gnu -L/usr/local/lib  -lgtest -lpthread -lgflags -lglog -lcurl -lboost_thread -lworkflow -ljsoncpp -I/usr/include -g 
if [ $? -eq 0 ]; then
	./a.out -test=true
else
	echo "build G++ ERROR"
fi
# start test case
#./a.out -test=true
