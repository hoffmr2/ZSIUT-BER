//
// Created by MHofffmann on 6/6/2018.
//

#include "BERName.h"

#include <iostream>
#include <fstream>
#include <exception>

using std::ifstream;
using std::unique_ptr;
using std::runtime_error;
using std::string;
using std::make_shared;
BERName::BERName(string a_ConfigPath) : BER(m_TypeTag ), m_ConfigXml() {


}

string BERName::file2char(string fileName) {

    std::fstream f(fileName, std::fstream::in );
    string s;
    std::getline( f, s, '\0');
    auto last = s.find_last_of(">");
    s = s.substr(0, last+1);
    f.close();

    return s;
}

void BERName::AppendBytes(std::vector<Byte> &output, const std::vector<Byte> &bytes) const {

    for(auto& byte : bytes) {

        output.push_back(byte);
    }
}

std::vector<Byte> BERName::Name2Bytes() {
    std::vector<Byte> output;

    auto bytes = m_FN->GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_SN->GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_AD->GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_AGE->GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_Details->GetEncoded();
    AppendBytes(output, bytes);
    bytes = m_OrdLev->GetEncoded();
    AppendBytes(output, bytes);
    return output;
}

void BERName::saveBinary(string a_Path) {

    std::fstream output(a_Path, std::ios::out | std::ios::binary);

    if(output.is_open() == false) {

        return;
    }

    for(auto& byte : m_Encoded){
        output << byte;
    }

   // output.flush();
    output.close();
}

void BERName::loadData(string a_ConfigPath) {


    string xmlFileContext = file2char( a_ConfigPath );

    try
    {
        m_ConfigXml.parse < 0 >( (char*)xmlFileContext.c_str()); // (2)
    }
    catch( const parse_error & e )
    {
        std::cerr << e.what() << " here: " << e.where < char >() << std::endl;
    }

    m_NameNode = m_ConfigXml.first_node();
    m_FN = make_shared<BERString>(m_NameNode->first_node("fn")->value(), 0x68); // application depend tag 8
    m_SN = make_shared<BERString>(m_NameNode->first_node("sn")->value(), 0x69); // application depend tag 9
    m_AD = make_shared<BERString>(m_NameNode->first_node("ad")->value(), 0x6a); // application depend tag 10
    auto age = std::stoi(m_NameNode->first_node("age")->value());
    m_AGE = make_shared<BERInteger>(age);


    auto structNode = m_NameNode->first_node("struct");
    string structName = structNode->first_node("name")->value();
    string structF2 = structNode->first_node("f2")->value();
    int structF3 = std::stoi(structNode->first_node("f3")->value());
    std::vector<float> structF4;
    for( xml_node <>* value = structNode->first_node("f4")->first_node(); value; value = value->next_sibling() ) {

        structF4.push_back(std::stof(value->value()));
    }

    std::vector<float> structF5;
    for( xml_node <>* value = structNode->first_node("f5")->first_node(); value; value = value->next_sibling() ) {

        structF5.push_back(std::stof(value->value()));
    }
    std::vector<char> structF6;
    for( xml_node <>* value = structNode->first_node("f6")->first_node(); value; value = value->next_sibling() ) {

        structF6.push_back(std::stoi(value->value()));
    }
    m_Details = make_shared<BERDetails>(structName,
                                        structF2,
                                        structF3,
                                        structF4,
                                        structF5,
                                        structF6);


    std::vector<float> array;
    for( xml_node <>* value = m_NameNode->first_node("array")->first_node(); value; value = value->next_sibling() ) {

        array.push_back(std::stof(value->value()));
    }

    m_OrdLev = make_shared<BEROrdLev>(array);

    m_Value = Name2Bytes();
    EncodeLength();
    Encode();

}

void BERName::show(string path) {

    std::fstream f(path, std::fstream::in );
    string s;
    std::getline( f, s, '\0');
    auto last = s.find_last_of(">");
    s = s.substr(0, last+1);

    std::cout << s << std::endl;
    f.close();
}
