//
// Created by MHofffmann on 5/13/2018.
//

#include "BERInteger.h"
#include <iostream>

BERInteger::BERInteger(int a_Value) : BER(m_TypeTag) {

    m_Value = Int2Bytes(a_Value);
    EncodeLength();
    Encode();

}

std::vector<Byte> BERInteger::Int2Bytes(int a_Value) {

    std::vector<Byte> output;
    const auto bytes_number = sizeof(a_Value);
    char bytes[bytes_number];
    std::copy(static_cast<const char*>(static_cast<const void*>(&a_Value)),
              static_cast<const char*>(static_cast<const void*>(&a_Value)) + bytes_number,
              bytes);

    for(size_t i=0; i < bytes_number; ++i){

        output.push_back(bytes[i]);

    }
    return output;
}
