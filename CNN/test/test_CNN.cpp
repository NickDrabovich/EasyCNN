#include <gtest/gtest.h>
#include <CNN.h>

TEST(CNNTest, Operators) {
    cnn::CNN* cnn = new cnn::CNN();
    EXPECT_FALSE(cnn == 0);
    delete cnn;
}

TEST(CNNTest, Methods) {
    EXPECT_TRUE(11 == 11);
    EXPECT_FALSE(11 == 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
