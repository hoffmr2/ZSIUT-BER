//
// Created by MHofffmann on 5/13/2018.
//

#ifndef ZSIUT_BERINTEGER_H
#define ZSIUT_BERINTEGER_H

#include "BER.h"
#include <vector>
#include <cstdint>


class BERInteger : public BER {
public:
    BERInteger(int a_Value);

private:
   static const Byte m_TypeTag = 0x02;

   std::vector<Byte> Int2Bytes(int a_Value);
};


#endif //ZSIUT_BERINTEGER_H
