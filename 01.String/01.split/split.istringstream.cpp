/*******************************************************************************
 *      file name: split.istringstream.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-14:55:23                              
 *  modified time: 2022/01/12-14:55:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void split(const string& s,vector<int>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
    return;
}

int main() {
    string s("123:456:7");
    vector<int> sv;
    split(s, sv, ':');
    for (const auto& s : sv) {
        cout << s << endl;
    }
    system("pause");
    return 0;
}
