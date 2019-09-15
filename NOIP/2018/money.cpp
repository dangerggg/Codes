#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

// 各种类型的背包问题要熟练掌握，最基本的是01背包问题以及基于01背包问题的相应扩展，可以将这部分知识整理出来到时候带到考场
int main(){
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    int iters = 0, n = 0, cnt = 0;
    int money[105] = {0}, credit[30000];
    cin >> iters;
    for (int i = 0; i < iters; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
           cin >> money[j]; 
        }
        // below are the algorithm part
        
        memset(credit, -10000, sizeof(credit));
        credit[0] = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = money[j]; k < 30000; ++k) {
                credit[k] = max(credit[k - money[j]] + 1, credit[k]);
            }
        }
        cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (credit[money[j]] == 1) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}