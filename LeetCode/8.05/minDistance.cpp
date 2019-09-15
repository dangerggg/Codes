#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int my_min(int x, int y, int z){
        if(x < y){
            if(x < z) return x;
            else return z;
        }
        else{
            if(y < z) return y;
            else return z;
        }
    }

    int minDistance(string word1, string word2) {
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int> > dp(size1+1, vector<int>(size2+1, 0));
        for(int i = 0; i <= size2; ++i) dp[0][i] = i;
        for(int j = 0; j <= size1; ++j) dp[j][0] = j;
        for(int i = 1; i <= size1; ++i){
            for(int j = 1; j <= size2; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = my_min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                }
            }
        } 
        
        for(int i = 0; i <= size1; ++i){
            for(int j = 0; j <= size2; ++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        } 
        return dp[size1][size2];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);
        
        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}