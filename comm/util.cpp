#include "util.h"
#include <iostream>

int MAXCOUNT=888;
namespace comm_ss
{
void Test(int a,int b){
    std::cout << a+b << std::endl;
}
int getMM(){
    return MAXCOUNT;
}
}