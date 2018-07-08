cmake_minimum_required(VERSION 3.10)
project(ZSiUT)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(lib/rapidxml-1.13)


add_executable(ZSiUT source/main.cpp source/BERInteger.cpp source/BERInteger.h source/BER.cpp source/BER.h source/BERReal.cpp source/BERReal.h source/BERString.cpp source/BERString.h source/BEROrdLev.cpp source/BEROrdLev.h source/BERBitString.cpp source/BERBitString.h source/BERDetails.cpp source/BERDetails.h source/BERName.cpp source/BERName.h)
add_executable(Test  source/BER.cpp source/BERInteger.cpp source/BERInteger.h source/BER.h Tests/main_test.cpp Tests/BERTest.cpp Tests/BERIntegerTest.cpp source/BERReal.cpp source/BERReal.h Tests/BERRealTest.cpp source/BERString.cpp source/BERString.h Tests/BERStringTest.cpp source/BEROrdLev.cpp source/BEROrdLev.h Tests/BEROrdLevTest.cpp source/BERBitString.cpp source/BERBitString.h Tests/BitStringTest.cpp source/BERDetails.cpp source/BERDetails.h source/BERName.cpp source/BERName.h)
target_link_libraries(Test gtest gtest_main)