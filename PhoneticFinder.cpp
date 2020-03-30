#include <bits/stdc++.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include "PhoneticFinder.hpp"
using namespace std;



string phonetic::find(string text, string word)
{
    if(word =="")throw out_of_range{"empty String"};
    string originWord =word;
    string ans = " ";
    string ans2 = " ";
    int counter = 0;
    transform(word.begin(),word.end(),word.begin(),::tolower);
    for (int i = 0; i<text.length(); ++i)
    {
        if(text[i] != ' ')
        {
            ans.append(1u,text[i]);
        }
        if(text[i] == ' ' || i == text.length()-1)
        {
            if(ans.length() == word.length())
            {
                ans2 = ans;
                transform(ans.begin(),ans.end(),ans.begin(),::tolower);
                for(int i = 0;i < word.length();++i)
                {
                    counter += mistakes(ans[i],word[i]);
                }
                if(counter == word.length())
                {
                    return ans2;
                }
            }
            ans.clear();
            counter = 0;
        }
    }
}

int mistakes(char c1,char c2)
{
    if( (c2 == 'w' || c2 == 'v') && (c1 == 'w' || c1 == 'v'))
    {
        return 1;
    }
    if( (c2 == 'b' || c2 == 'f'|| c2 == 'p') && (c1 == 'b' || c1 == 'f' || c1 == 'p'))
    {
        return 1;
    }
    if( (c2 == 'g' || c2 == 'j') && (c1 == 'g' || c1 == 'j'))
    {
        return 1;
    }
    if( (c2 == 'c' || c2 == 'k'|| c2 == 'q') && (c1 == 'c' || c1 == 'k' || c1 == 'q'))
    {
        return 1;
    }
    if( (c2 == 's' || c2 == 'z') && (c1 == 's' || c1 == 'z'))
    {
        return 1;
    }
    if( (c2 == 't' || c2 == 'd') && (c1 == 't' || c1 == 'd'))
    {
        return 1;
    }
    if( (c2 == 'o' || c2 == 'u') && (c1 == 'o' || c1 == 'u'))
    {
        return 1;
    }
    if( (c2 == 'i' || c2 == 'y') && (c1 == 'i' || c1 == 'y'))
    {
        return 1;
    }
    if(c1 == c2)
    {
        return 1;
    }
    return 0;
}
