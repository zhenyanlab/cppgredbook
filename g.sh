#g++ -std=c++11 `pkg-config --cflags --libs protobuf` -I/include -I/usr/local/include -I/usr/local/include  -L/lib -L/usr/local/lib   -lprotobuf -lprotobuf-lite  -lprotoc -lpthread -lgrpc -lgrpc++  -lgrpc++_reflection -ldl  -o a.out  ./grpc/*.cc ./greeter-server.cpp
#g++ -std=c++11  -I/include -I/usr/local/include  -L/usr/local/lib   -lgrpc++_reflection -lgrpc++   /usr/local/lib/libprotobuf.a   -lpthread   -ldl  -o a.out  ./grpc/*.cc ./greeter-server.cpp


g++ -std=c++11 -I/include -L/lib `pkg-config --libs --static protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl -o a.out  ./grpc/*.cc ./greeter-server.cpp

#g++ -std=c++11 `pkg-config --cflags --libs protobuf` -I/include -I/usr/local/include   -L/lib -L/usr/local/lib    -lpthread  ./grpc/*.cc ./greeter-server.cpp

if [ $? -eq 0 ]; then
	./a.out -test=true
else
	echo "build G++ ERROR"
fi
# start test case
# setenv("MALLOC_TRACE", "mtrace.out", 1)
#./a.out -test=true
