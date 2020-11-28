/*******************************************************************************
 *      file name: occurrences_after_bigram.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/08-22:01:05                              
 *  modified time: 2020/10/08-22:01:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string get(string str, int pos) {
        int i = pos;
        for (; i < str.length(); i++)
        {
            if (str[i] == ' ' || str[i] == '\n') break;
        }
        if( i != pos) return str.substr(pos, i-pos);
        return string("");
    }
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        text = " " + text;
        string word = " " + first + " " + second + " ";
        int pos = 0;
        while (pos != string::npos && pos < text.length()) {
            pos = text.find(word, pos);
            if (pos != string::npos) 
            {
                pos = pos + word.length() - 1;
                if (pos < text.length()) {
                    string tmp = get(text, pos+1);
                    if (tmp != string(""))
                        res.push_back(tmp);
                }
                    
            }
        }
        return res;
        
    }
};
int main()
{}
