//
// Created by MHofffmann on 5/13/2018.
//

#include "../source/BER.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>

struct BERTest : public ::testing::Test {

    std::shared_ptr<BER> m_BER = nullptr;
    Byte type = 0x02;
    std::vector<Byte> value;

    BERTest() {

        for(size_t i =0; i < 100; ++i) {

            value.push_back(0x44);
        }
        m_BER = std::make_shared<BER>(BER(type, value));

    }
};

TEST_F(BERTest, BEREncode) {

   auto output = m_BER->GetEncoded();
   EXPECT_EQ(output[0], 0x02);
   EXPECT_EQ(output[1], 100);

   for(size_t i = 2; i < output.size(); ++i) {

       EXPECT_EQ(output[i], 0x44);
   }

}