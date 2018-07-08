//
// Created by MHofffmann on 5/26/2018.
//

#include "../source/BERBitString.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>


struct BERBitStringTest : public ::testing::Test {

    std::shared_ptr<BERBitString> m_BER = nullptr;
    std::vector<char> value = {1,1, 0, 0, 1, 1, 0, 0, 1, 1};

    BERBitStringTest() {

        m_BER = std::make_shared<BERBitString>(BERBitString(value));

    }
};

TEST_F(BERBitStringTest, EncodeWorks) {

    auto output = m_BER->GetEncoded();
    EXPECT_EQ(output[0], 0x03);
    EXPECT_EQ(output[1], 0x03);
    EXPECT_EQ(output[2], 0x06);
    EXPECT_EQ(output[3], 0xcc);
    EXPECT_EQ(output[4], 0xc0);


}