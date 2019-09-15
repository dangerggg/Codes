#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int size = arr1.size();
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int max4 = 0;
        int max5 = 0;
        int max6 = 0;
        int max7 = 0;
        int max8 = 0;
        for(int i = 0; i < size; ++i){
            max1 = max(arr1[i] + arr2[i] + i, max1);
            max2 = max(arr1[i] + arr2[i] - i, max2);
            max3 = max(0 - arr1[i] + arr2[i] + i, max3);
            max4 = max(0 - arr1[i] + arr2[i] - i, max4);
            max5 = max(arr1[i] - arr2[i] + i, max5);
            max6 = max(arr1[i] - arr2[i] - i, max6);
            max7 = max(-arr1[i] - arr2[i] + i, max7);
            max8 = max(-arr1[i] - arr2[i] - i, max8);
        }
        return max(max(max1 + max8, max2 + max7), max(max3 + max6, max4 + max5));
    }
};