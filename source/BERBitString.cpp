//
// Created by MHofffmann on 5/19/2018.
//

#include "BERBitString.h"
#include <cmath>
#include <iostream>

std::vector<Byte> BERBitString::BitString2Bytes(std::vector<char>& a_Bits) {

    std::vector<Byte> output;
    const size_t bits_per_byte = 8;
    auto bytes_number = std::ceil(a_Bits.size() / static_cast<float>(bits_per_byte));
    auto unused_bits = bits_per_byte - a_Bits.size() % bits_per_byte;
    output.push_back(static_cast<Byte>(unused_bits));

    for(size_t i = 0; i < bytes_number - 1; ++i){

        Byte tmp = 0;
        for(size_t j = bits_per_byte; j > 0; --j) {

            size_t k =  bits_per_byte - j;
            int bit = (a_Bits[i*bits_per_byte + k] == 0)? 0 : 1;
            tmp += static_cast<Byte>(bit * std::pow(2, j-1));
        }
        output.push_back(tmp);
    }

    // Extra byte with some bits unused
   if(unused_bits > 0) {
        Byte tmp = 0;
        for (size_t j = bits_per_byte; j > unused_bits; --j) {

            size_t k = bits_per_byte - j;
            int bit = (a_Bits[(bytes_number - 1) * bits_per_byte + k] == 0)? 0 : 1;
            tmp += static_cast<Byte>(bit * std::pow(2, j - 1));
        }
        output.push_back(tmp);
    }

    return output;
}

BERBitString::BERBitString(std::vector<char>& a_Bits) : BER(m_TypeTag) {

    m_Value = BitString2Bytes(a_Bits);
    EncodeLength();
    Encode();

}
