#include <cstdio>
#include <cstring>
#include <algorithm>

#define GRADE(i0, i1, i2, i3) i0+i1+i2+i3
using namespace std;

const int CARD = 40;
const int M = 125;
const int N = 355;

int dp[CARD][CARD][CARD][CARD] = {0};

int main(){
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    int bonus[N], valid[4], cards;
    memset(bonus, 0, sizeof(bonus));
    memset(valid, 0, sizeof(valid));
    for(int i = 0; i < n; ++i) scanf("%d", &bonus[i]);
    for(int i = 0; i < m; ++i){
        scanf("%d", &cards);
        ++valid[cards - 1];
    }
    dp[0][0][0][0] = bonus[0];
    for(int i0 = 0; i0 <= valid[0]; ++i0)
        for(int i1 = 0; i1 <= valid[1]; ++i1)
            for(int i2 = 0; i2 <= valid[2]; ++i2)
                for(int i3 = 0; i3 <= valid[3]; ++i3){
                    if(i0 > 0){
                        dp[i0][i1][i2][i3] = max(dp[i0-1][i1][i2][i3] + bonus[GRADE(i0, i1*2, i2*3, i3*4)], dp[i0][i1][i2][i3]); 
                    }
                    if(i1 > 0){
                        dp[i0][i1][i2][i3] = max(dp[i0][i1-1][i2][i3] + bonus[GRADE(i0, i1*2, i2*3, i3*4)], dp[i0][i1][i2][i3]); 
                    }
                    if(i2 > 0){
                        dp[i0][i1][i2][i3] = max(dp[i0][i1][i2-1][i3] + bonus[GRADE(i0, i1*2, i2*3, i3*4)], dp[i0][i1][i2][i3]); 
                    }
                    if(i3 > 0){
                        dp[i0][i1][i2][i3] = max(dp[i0][i1][i2][i3-1] + bonus[GRADE(i0, i1*2, i2*3, i3*4)], dp[i0][i1][i2][i3]);
                    }
                }
    
    printf("%d", dp[valid[0]][valid[1]][valid[2]][valid[3]]);
}