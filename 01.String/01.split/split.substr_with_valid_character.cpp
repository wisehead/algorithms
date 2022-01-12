/*******************************************************************************
 *      file name: split.substr_with_valid_character.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-14:50:32                              
 *  modified time: 2022/01/12-14:50:32                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
std::vector<std::string> split(std::string str,std::string pattern, char valid)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    int ps = pattern.size();
    int last_pos = 0;

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            if (pos+ps < size && str[pos+ps] == valid) continue;
            std::string s=str.substr(last_pos,pos-last_pos);
            result.push_back(s);
            i=pos+pattern.size()-1;
            last_pos = pos + ps;
        }
    }
    return result;
} 
int main()
{}
