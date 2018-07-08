//
// Created by MHofffmann on 5/19/2018.
//

#include "BEROrdLev.h"
#include "BERReal.h"

BEROrdLev::BEROrdLev(std::vector<float> a_Value) : BER(m_TypeTag) {

    m_Value = OrdLev2Bytes(a_Value);
    EncodeLength();
    Encode();
}

std::vector<Byte> BEROrdLev::OrdLev2Bytes(std::vector<float> &a_Value) {

    std::vector<Byte> output;

    for(auto& value : a_Value) {

        auto tmp = BERReal(value);
        std::vector<Byte> value_bytes = tmp.GetEncoded();

        output.insert(output.end(), value_bytes.begin(), value_bytes.end());
    }
    return output;
}
