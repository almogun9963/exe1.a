#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

namespace phonetic
{

    std::string toLowerCase(std::string s);

    bool isLike(std::string s1,std::string s2);

    bool isLike(char c1,char c2);

    std::string find(std::string s1, std::string s2);

    std::string getword(int start,int end, std::string s);
};