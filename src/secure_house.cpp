#include <iostream>
#include <string>
#include "house.hpp"

std::string owner_name;

int main(int argc, char * argv[])
{
    owner_name = (std::string)argv[1];
    std::cout << "Owner name: " << owner_name << std::endl;
    KeyList keyList;
    //std::cout << "Valid keys: " << std::endl;
    for(int i = 2; i < argc; i++)
    {
        keyList.push((std::string)argv[i]);
    }
    std::cout << keyList.search("sadfasds") << std::endl;
    keyList.~KeyList();
}