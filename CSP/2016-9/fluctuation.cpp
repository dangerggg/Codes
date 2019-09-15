#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1005;
int main(){
    int n = 0, stock[N], max_fluc = 0;
    memset(stock, 0, sizeof(stock));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &stock[i]);
    }
    for(int i = 1; i < n; ++i){
        if(abs(stock[i] - stock[i-1]) > max_fluc) max_fluc = abs(stock[i] - stock[i-1]);
    }
    printf("%d", max_fluc);
    return 0;
}