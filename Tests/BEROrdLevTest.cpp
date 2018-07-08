//
// Created by MHofffmann on 5/19/2018.
//

#include "../source/BEROrdLev.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>



struct BEROrdLevTest : public ::testing::Test {

    std::shared_ptr<BEROrdLev> m_BER = nullptr;
    std::vector<float> value = {0.5, 1, 20, 55, 2, 12, 11, 22, 3, 0, 0, 5, 1, 1, 0, 55, 2, 3,
                                0.5, 1, 20, 36, 8, 7, 7, 6, 5, 3, 2, 100, 50, 23};

    BEROrdLevTest() {

        m_BER = std::make_shared<BEROrdLev>(BEROrdLev(value));

    }
};

TEST_F(BEROrdLevTest, EncodeWorks) {

    auto output = m_BER->GetEncoded();

    EXPECT_EQ(output[4], 0x04);
    EXPECT_EQ(output[3], 0x09);
    EXPECT_EQ(output[2], 0xC0);
    EXPECT_EQ(output[1], 0x81);
    EXPECT_EQ(output[0], 0x30);
}

