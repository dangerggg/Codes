#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005;

int main(){
    int n = 0, number = 0, a[N];
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &number);
        ++a[number];
    }
    int tot = 0, tot_surfix = 0;
    for(int i = 0; i < N; ++i){
        tot += a[i];
        if(n%2 == 0){
            if(tot == n/2){
                printf("%d", -1);
                break;
            }
            else if(tot > n/2){
                for(int j = i+1; j < N; ++j)
                    tot_surfix += a[j];
                if(tot-a[i] == tot_surfix) printf("%d", i);
                else printf("%d", -1);
                break;
            }
        }
        else{
            if(tot > n/2){
                for(int j = i+1; j < N; ++j)
                    tot_surfix += a[j];
                if(tot-a[i] == tot_surfix) printf("%d", i);
                else printf("%d", -1);
                break;
            }
        }
    }   
    return 0;
    
}