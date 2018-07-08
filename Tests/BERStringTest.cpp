//
// Created by MHofffmann on 5/16/2018.
//

#include "../source/BERString.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>



struct BERStringTest : public ::testing::Test {

    std::shared_ptr<BERString> m_BER = nullptr;
    const char* value = "twoja_stara";

    BERStringTest() {

        m_BER = std::make_shared<BERString>(BERString(value));

    }
};

TEST_F(BERStringTest, EncodeWorks) {

    auto output = m_BER->GetEncoded();

    EXPECT_EQ(output[12], 'a');
    EXPECT_EQ(output[5], 'j');
    EXPECT_EQ(output[4], 'o');
    EXPECT_EQ(output[3], 'w');
    EXPECT_EQ(output[2], 't');
    EXPECT_EQ(output[1], 11);
    EXPECT_EQ(output[0], 0x04);
}