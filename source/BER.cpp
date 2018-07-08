//
// Created by MHofffmann on 5/13/2018.
//

#include "BER.h"
#include <cmath>

BER::BER(const Byte m_Type, std::vector<Byte> m_Value) : m_Type(m_Type),
                                                         m_Value(m_Value)
{
    EncodeLength();
    Encode();
}

void BER::EncodeLength() {

    auto bytes_number = m_Value.size();
    if( bytes_number <= 127) {

        m_Length.push_back(bytes_number);
    }
    else {

        const auto values_per_byte = 256; // 8 bit Byte can represent 256 values
        auto length_bytes = std::ceil(std::log(static_cast<float>(bytes_number)) / std::log(values_per_byte));
        auto long_format_id = 0b10000000;
        m_Length.push_back(long_format_id + length_bytes);

        do {
            auto reminder = bytes_number % values_per_byte;
            bytes_number /= values_per_byte;
            m_Length.push_back(static_cast<Byte>(reminder));
        }while(bytes_number > 0);


    }

}

void BER::Encode() {

    m_Encoded.push_back(m_Type);
    for(auto& byte : m_Length){

        m_Encoded.push_back(byte);
    }

    for(auto& byte : m_Value){

        m_Encoded.push_back(byte);
    }

}

BER::BER(Byte a_Type) : m_Type(a_Type) {

}
