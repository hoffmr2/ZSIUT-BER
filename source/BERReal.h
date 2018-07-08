//
// Created by MHofffmann on 5/16/2018.
//

#ifndef ZSIUT_BERREAL_H
#define ZSIUT_BERREAL_H

#include "BER.h"

class BERReal : public BER {

private:
    static const Byte m_TypeTag = 0x09;
    std::vector<Byte> Float2Bytes(float a_Value);

public:
    BERReal(float a_Value);

};


#endif //ZSIUT_BERREAL_H
