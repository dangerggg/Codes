#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 105;
int main(){
    int n = 0, quest = 0, vacant_row[20], vacant_seat[100];
    for(int y = 0; y < 20; ++y) vacant_row[y] = 5;
    memset(vacant_seat, 0, sizeof(vacant_seat));
    scanf("%d", &n);
    int i, j, k;
    for(i = 0; i < n; ++i){
        scanf("%d", &quest);
        for(j = 0; j < 20; ++j){
            if(vacant_row[j] >= quest) break;
        }
        if(j == 20){
            for(k = 0; k < 100; ++k){
                if(vacant_seat[k] == 0){
                    --quest;
                    vacant_seat[k] = 1;
                    --vacant_row[k/5];
                    printf("%d ", k+1);
                }
            }
        }
        else{
            vacant_row[j] -= quest;
            for(k = j*5; k < (j+1)*5; ++k){
                if(vacant_seat[k] == 0){
                    for(int x = 0; x < quest; ++x){
                        vacant_seat[x+k] = 1;
                        printf("%d ", x+k+1); 
                    }
                    break;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}