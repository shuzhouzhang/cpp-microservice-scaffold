/*
    1.包含头文件<gtest/gtest.h>
    2.定义测试套件
        1.使用TEST宏定义测试套件和测试用例
    3.运行测试用例
*/

#include <gtest/gtest.h>
#include<iostream>
#include<unordered_map>

class LocalTestSuite : public testing::Test {
    public:
    virtual void SetUp() {
        std::cout << "执行于每个用例之前" << std::endl;
        map.insert(std::make_pair(1, 1));
        map.insert(std::make_pair(2, 2));
        map.insert(std::make_pair(3, 3));
    }
    virtual void TearDown() {
        std::cout << "执行于每个用例之后" << std::endl;
        map.clear(); 
    }
    public:
    std::unordered_map<int, int> map;
};

TEST_F(LocalTestSuite, find) {
    ASSERT_EQ(map.size(), 3);
    ASSERT_EQ(map.find(1)->second, 1);
    map.erase(1);
}

TEST_F(LocalTestSuite, remove) {
    map.erase(1);
    ASSERT_EQ(map.size(), 2);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}