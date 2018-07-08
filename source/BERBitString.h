//
// Created by MHofffmann on 5/19/2018.
//

#ifndef ZSIUT_BERBITSTRING_H
#define ZSIUT_BERBITSTRING_H

#include "BER.h"
#include <vector>

class BERBitString : public BER {

public:
    explicit BERBitString(std::vector<char>& a_Bits);

private:
    static const Byte m_TypeTag = 0x03;

    std::vector<Byte> BitString2Bytes(std::vector<char>& a_Bits);

};


#endif //ZSIUT_BERBITSTRING_H
