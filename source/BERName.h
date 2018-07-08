//
// Created by MHofffmann on 6/6/2018.
//

#ifndef ZSIUT_BERNAME_H
#define ZSIUT_BERNAME_H

#include "BERDetails.h"
#include <rapidxml.hpp>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using namespace rapidxml;

class BERName : public BER{

public:
    explicit BERName(string a_ConfigPath);

    static string file2char(string fileName);

    void saveBinary(string a_Path);
    void loadData(string a_ConfigPath);
    void show(string path);

private:

    static const Byte m_TypeTag = 0x30;
    xml_document <> m_ConfigXml;
    xml_node <>* m_NameNode = nullptr;

    shared_ptr<BERString> m_FN = nullptr;
    shared_ptr<BERString> m_SN = nullptr;
    shared_ptr<BERString> m_AD = nullptr;
    shared_ptr<BERInteger> m_AGE = nullptr;
    shared_ptr<BERDetails> m_Details = nullptr;
    shared_ptr<BEROrdLev> m_OrdLev = nullptr;

    std::vector<Byte> Name2Bytes();
    void AppendBytes(std::vector<Byte> &output, const std::vector<Byte> &bytes) const;
};


#endif //ZSIUT_BERNAME_H
