//
// Created by MHofffmann on 5/30/2018.
//

#include "BERDetails.h"



BERDetails::BERDetails(string a_Name,
                       string a_F2,
                       int a_F3,
                       std::vector<float> a_F4,
                       std::vector<float> a_F5,
                       std::vector<char> a_F6)
        :   BER(m_TypeTag),
            m_Name(a_Name.c_str(), 0),
            m_F2(a_F2.c_str(), 0),
            m_F3(a_F3),
            m_F4(a_F4),
            m_F5(a_F5),
            m_F6(a_F6)

{

    if(a_Name.size() != m_NameLength) {

        throw WrongArgumentException("a_Name wrong length must be:" + std::to_string(m_NameLength));
    }

    if(a_F2.size() != m_F2Length) {

        throw WrongArgumentException("a_F2 wrong length must be:" + std::to_string(m_F2Length));
    }

    if(a_F3 > m_F3Max || a_F3 < m_F3Min) {

        throw WrongArgumentException("a_F3 wrong value must be from: " +
                                     std::to_string(m_F3Min) + "to" + std::to_string(m_F3Max));
    }

    if(a_F6.size() != m_F6Length) {

        throw WrongArgumentException("a_F6 wrong length must be:" + std::to_string(m_F6Length));
    }

    m_Value = Details2Bytes();
    EncodeLength();
    Encode();
}

std::vector<Byte> BERDetails::Details2Bytes() {

    std::vector<Byte> output;

    auto bytes = m_Name.GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_F2.GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_F3.GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_F4.GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_F5.GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_F6.GetEncoded();
    AppendBytes(output, bytes);
    return output;
}

void BERDetails::AppendBytes(std::vector<Byte> &output, const std::vector<Byte> &bytes) const {
    for(auto& byte : bytes) {

        output.push_back(byte);
    }
}
