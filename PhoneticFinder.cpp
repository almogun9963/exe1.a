#include <stdexcept>
#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

namespace phonetic{

    std::string toLowerCase(std::string s){
        for (size_t i = 0; i < s.length(); i++)
        {
            s[i] = std::tolower(s[i]);
        }
        return s;

    }

    bool isLike(char c1,char c2){
        c1 = std::tolower(c1);
        c2 = std::tolower(c2);
        if (c1==c2)
        {
            return true;
        }
        if (c1=='q' && (c2=='k'||c2=='c'))
        {
            return true;
        }
        if (c1=='w'&&c2=='v')
        {
            return true;
        }
        if (c1=='t'&&c2=='d')
        {
            return true;
        }
        if (c1=='y'&&c2=='i')
        {
            return true;
        }
        if (c1=='u'&&c2=='o')
        {
            return true;
        }
        if (c1=='i'&&c2=='y')
        {
            return true;
        }
        if (c1=='o'&&c2=='u')
        {
            return true;
        }
        if (c1=='p'&&(c2=='f'||c2=='b'))
        {
            return true;
        }
        if (c1=='o'&&c2=='u')
        {
            return true;
        }
        if (c1=='d'&&c2=='t')
        {
            return true;
        }
        if (c1=='f'&&(c2=='p'||c2=='b'))
        {
            return true;
        }
        if (c1=='g'&&c2=='j')
        {
            return true;
        }
        if (c1=='j'&&c2=='g')
        {
            return true;
        }
        if (c1=='k'&&(c2=='c'||c2=='q'))
        {
            return true;
        }
        if (c1=='c'&&(c2=='k'||c2=='q'))
        {
            return true;
        }
        if (c1=='v'&&c2=='w')
        {
            return true;
        }
        if (c1=='b'&&(c2=='f'||c2=='p'))
        {
            return true;
        }
        if (c1=='s'&&c2=='z')
        {
            return true;
        }
        if (c1=='z'&&c2=='s')
        {
            return true;
        }
        return false;
    }
    bool isLike(std::string s1,std::string s2){
        if (s1.length()!=s2.length()){
            return false;
        }
        bool flag = true;
        for (size_t i = 0; i < s1.length() && flag; i++)
        {
            if (!(isLike(s1[i],s2[i])||isLike(s2[i],s1[i])))
            {
                flag=false;
            }

        }
        return flag;


    }

    std::string getword(int start,int end, std::string s){
        std::string temp = "";
        for (size_t i = start; i < end; i++)
        {
            if (i==end-1&&s[i]==' ')
                return temp;
            temp += s[i];
        }
        return temp;
    }

    std::string find(std::string s1, std::string s2){
        if(s2.compare(" ")==0){
            std::string errorMessage1 = std::string("input ERROR");
            throw std::runtime_error(errorMessage1);
        }
        int startW = 0;
        int endW;
        char space = ' ';



        for (size_t i = 0; i < s1.length(); i++)
        {
            if (i==s1.length()-1)
            {
                endW = i+1;
                if(s1[i+1]==space){
                    endW=i;
                }
                std::string temp = getword(startW,endW,s1);
                if (isLike(temp,s2))
                {
                    return temp;
                }
                i++;
            }


            if (s1[i]==space&&i<s1.length())
            {
                endW = i;
                std::string temp = getword(startW,endW,s1);
                /*std::cout << temp2 << std::endl;*/
                if (isLike(temp,s2))
                {
                    return temp;
                }

                if (i+1<s1.length())
                {
                    startW = i+1;
                }


            }

        }
        std::string errorMessage = std::string("Did not find the word '")+s2+("' in the text");
        throw std::runtime_error(errorMessage);
    }
};