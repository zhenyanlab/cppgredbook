#include "gtest/gtest.h"
#include "Test.h"
#include "comm/util.h"
#include "comm/util2.h"

TEST(mfilecase,true) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(mfilecase,maxTest) {
    int max= comm_ss::getMM();
    int max2 = MAXCOUNT;
    int max3 = comm_ss::getMaxCount();
    int max4= comm_ss::getMMM();

    std::cout << max <<"|" << max2 <<"|"<< max3 <<"|"<< max4<<std::endl;
    EXPECT_EQ(max,max2);
    EXPECT_EQ(max3,max2);
    EXPECT_EQ(max3,max4);

    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

