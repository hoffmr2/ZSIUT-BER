//
// Created by MHofffmann on 5/19/2018.
//

#ifndef ZSIUT_BERORDLEV_H
#define ZSIUT_BERORDLEV_H

#include "BER.h"
#include <vector>
#include <cstdint>


class BEROrdLev : public BER{


public:
    BEROrdLev(std::vector<float> a_Value);

private:
    static const Byte m_TypeTag = 0x30;

    std::vector<Byte> OrdLev2Bytes(std::vector<float> &a_Value);
};



#endif //ZSIUT_BERORDLEV_H
