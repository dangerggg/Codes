#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    scanf("%d", &n);
    int road[n];
    int max_sum = 0, max_cnt = 0, cowork = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &road[i]);
    for (int i = 0; i < n-1; ++i) {
        if (road[i] > max_cnt) max_cnt = road[i];
        if (road[i] < road[i+1] || i == n-2) {
            max_sum = max_sum + max_cnt - cowork;
            cowork = road[i];
            max_cnt = 0;
        }
    }
    if (road[n-1] > road[n-2]) {
        max_sum = max_sum + road[n-1] - cowork;
    }
    printf("%d", max_sum);
    return 0;
}