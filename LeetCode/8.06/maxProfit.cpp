#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>


using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int minPrice = INT_MAX, maxProfit = 0;
        for(int i=0; i < size; ++i){
            if(prices[i] < minPrice) minPrice = prices[i];
            else if(prices[i] - minPrice > maxProfit) maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }

    int maxProfitHard(vector<int>& prices) {
        int size = prices.size();
        vector<int> dp(size+1, 0);
        vector<int> dp_inverse(size+1, 0);
        int minPrice = prices[0], inverse_maxPrice = prices[size-1];
        for (int i = 1; i < size; ++i){
            dp[i] = max(dp[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        for (int i = size-2; i >= 0; --i){
            dp_inverse[i] = max(dp_inverse[i+1], inverse_maxPrice - prices[i]);
            inverse_maxPrice = max(inverse_maxPrice, prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < size; ++i){
           if (dp[i] + dp_inverse[i] > maxProfit){
               maxProfit = dp[i] + dp_inverse[i];  
           }
        }
        return maxProfit;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfitHard(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}