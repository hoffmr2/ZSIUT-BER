//
// Created by MHofffmann on 5/16/2018.
//

#include "../source/BERReal.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>


struct BERRealTest : public ::testing::Test {

    std::shared_ptr<BERReal> m_BER = nullptr;
    float value = 1;

    BERRealTest() {

        m_BER = std::make_shared<BERReal>(BERReal(value));

    }
};

TEST_F(BERRealTest, EncodeWorks) {

    auto output = m_BER->GetEncoded();

    EXPECT_EQ(output[5], 0x3f);
    EXPECT_EQ(output[4], 0x80);
    EXPECT_EQ(output[3], 0x00);
    EXPECT_EQ(output[2], 0x00);
    EXPECT_EQ(output[1], 4);
    EXPECT_EQ(output[0], 0x09);
}