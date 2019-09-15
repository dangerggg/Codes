#include <iostream>
#include <regex>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        regex pattern1("[ ]*[+-]?(0|[1-9][0-9]*)[.[0-9]+]?(e[+-]?([1-9][0-9]*))?[ ]*");
        regex pattern2("[ ]*[+-]?[.[0-9]+](e[+-]?([1-9][0-9]*))?[ ]*");
        if(regex_match(s, pattern1)) return true;
        else if(regex_match(s, pattern2)) return true;
        return false;
    }
};

int main(){
    string s;
    cin >> s;
    Solution solu;
    cout << solu.isNumber(s);
}