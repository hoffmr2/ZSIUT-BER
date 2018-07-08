//
// Created by MHofffmann on 5/16/2018.
//

#include "BERReal.h"

BERReal::BERReal(float a_Value) : BER(m_TypeTag) {

    m_Value = Float2Bytes(a_Value);
    EncodeLength();
    Encode();

}

std::vector<Byte> BERReal::Float2Bytes(float a_Value) {

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
