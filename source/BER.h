//
// Created by MHofffmann on 5/13/2018.
//

#ifndef ZSIUT_BER_H
#define ZSIUT_BER_H

#include <cstdint>

typedef uint8_t Byte;
#include <vector>

class BER {
public:
    BER(Byte a_Type);
    BER(const Byte m_Type, std::vector<Byte> m_Value);
    inline std::vector<Byte>& GetEncoded() { return m_Encoded;}

protected:

    const Byte m_Type = 0;
    std::vector<Byte> m_Length;
    std::vector<Byte> m_Value;
    std::vector<Byte> m_Encoded;

    void EncodeLength();
    void Encode();

};


#endif //ZSIUT_BER_H
