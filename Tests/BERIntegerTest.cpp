//
// Created by MHofffmann on 5/15/2018.
//

#include "../source/BERInteger.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>


struct BERIntegerTest : public ::testing::Test {

    std::shared_ptr<BERInteger> m_BER = nullptr;
    int value = 0x44444444;

    BERIntegerTest() {

        m_BER = std::make_shared<BERInteger>(BERInteger(value));

    }
};

TEST_F(BERIntegerTest, EncodeWorks) {

    auto output = m_BER->GetEncoded();
    EXPECT_EQ(output[0], 0x02);
    EXPECT_EQ(output[1], 4);

    for(size_t i = 2; i < output.size(); ++i) {

        EXPECT_EQ(output[i], 0x44);
    }

}
