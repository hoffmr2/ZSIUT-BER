#include <iostream>
#include "BERName.h"

using std::string;

int main() {
    std::cout << "ZSiUT 2018 BER ENCODER" << std::endl;
    string xmlPath = "C:\\Users\\MHofffmann\\Documents\\Repos\\ZSiUT\\zsiutconfig.xml";
    string output = "Name.bin";

    BERName berName(xmlPath);

    berName.show(xmlPath);
    berName.loadData(xmlPath);
    berName.saveBinary(output);
    std::cin.get();
    return 0;
}