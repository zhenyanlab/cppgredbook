#pragma once
#include <iostream>
extern int  MAXCOUNT;
namespace comm_ss
{
    inline int getMaxCount(){
        std::cout << MAXCOUNT << std::endl;
        return MAXCOUNT;
    }
    int getMM();

} // namespace name



