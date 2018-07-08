//
// Created by MHofffmann on 5/30/2018.
//

#ifndef ZSIUT_BERDETAILS_H
#define ZSIUT_BERDETAILS_H

#include "BER.h"
#include "BERString.h"
#include "BEROrdLev.h"
#include "BERBitString.h"
#include "BERInteger.h"

#include <string>
#include <exception>

using std::string;

class BERDetails : public BER{
public:

class WrongArgumentException : public std::exception{

public:
    explicit WrongArgumentException(string a_Msg) : m_Msg(a_Msg) {}
    virtual const char* what() const noexcept override {return m_Msg.c_str();}
private:
    string m_Msg;
};
    explicit BERDetails(string a_Name,
                        string a_F2,
                        int a_F3,
                        std::vector<float> a_F4,
                        std::vector<float> a_F5,
                        std::vector<char> a_F6);

private:
    static const Byte m_TypeTag = 0x30;
    BERString m_Name;
    const size_t m_NameLength = 20;
    BERString m_F2;
    const size_t m_F2Length = 30;
    BERInteger m_F3;
    const int m_F3Min = 0;
    const int m_F3Max = 50;
    BEROrdLev m_F4;
    BEROrdLev m_F5;
    BERBitString m_F6;
    const size_t m_F6Length = 6;


    std::vector<Byte> Details2Bytes();
    void AppendBytes(std::vector<Byte> &output, const std::vector<Byte> &bytes) const;
};


#endif //ZSIUT_BERDETAILS_H
