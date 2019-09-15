#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int> >& dominoes) {
        int log[100] = {0};
        int size = dominoes.size();
        int self = 0, sym_self = 0, cnt = 0, temp = 0;
        for(int i = 0; i < size; ++i){
            self = dominoes[i][0] * 10 + dominoes[i][1];
            //sym_self = dominoes[i][1] * 10 + dominoes[i][0];
            ++log[self];
        }
        for(int i = 0; i < size; ++i){
            self = dominoes[i][0] * 10 + dominoes[i][1];
            sym_self = dominoes[i][1] * 10 + dominoes[i][0];
            if(log[self] != 0 || log[sym_self] != 0){
                if(self == sym_self)
                    temp = log[self];
                else
                    temp = log[self] + log[sym_self];
                cnt += temp * (temp - 1) / 2;
                log[self] = log[sym_self] = 0;
            }
             
        }
        return cnt;
    }
};