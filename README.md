# ZSIUT-BER
Project for "Network Management" on my MSc studies. Task is to encode message with given structure and values with basic encode rules (BER)

## Build Windows

require cmake

open cmd in project root dir and type following commands:
- mkdir build
- cd build
- cmake .. -G "Visual Studio 14" - for Visual Studio 2015
- cmake .. -G "Visual Studio 15" - for Visual Studio 2017

Binary files for running both app and unit tests are in bin directory

## config file

in zsiutconfig.xml you can change values to custom ones