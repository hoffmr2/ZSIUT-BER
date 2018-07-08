//
// Created by MHofffmann on 5/16/2018.
//

#include "BERString.h"
#include <string.h>
#include <memory>

std::vector<Byte> BERString::Char2Bytes(const char *a_Value) {

    std::vector<Byte> output;
    auto bytes_number = strlen(a_Value);
    char* bytes = new char[bytes_number];
    std::copy(static_cast<const char*>(static_cast<const void*>(a_Value)),
              static_cast<const char*>(static_cast<const void*>(a_Value)) + bytes_number,
              bytes);

    for(size_t i=0; i < bytes_number; ++i){

        output.push_back(bytes[i]);
    }
    return output;
}

BERString::BERString(const char *a_Value) : BER(m_TypeTag) {

    m_Value = Char2Bytes(a_Value);
    EncodeLength();
    Encode();

}
