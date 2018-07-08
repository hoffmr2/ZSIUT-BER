//
// Created by MHofffmann on 5/16/2018.
//

#ifndef ZSIUT_BERSTRING_H
#define ZSIUT_BERSTRING_H

#include "BER.h"

class BERString : public BER {

public:
    BERString(const char *a_Value, const Byte a_TypeTag = 0x04);

private:
    static const Byte m_TypeTag = 0x04;
    std::vector<Byte> Char2Bytes(const char* a_Value);

};


#endif //ZSIUT_BERSTRING_H
