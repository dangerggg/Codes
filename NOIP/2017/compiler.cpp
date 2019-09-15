#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    char complexity[10], codes[20];
    int t = 0, line = 0, iters = 0, variable[26], levels = 0, depth = 0;
    bool error = false, fake = false;
    stack<char> active;
    stack<int> valid, inverse;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d", &line);
        scanf("%s", complexity);
        getchar();
        iters = 0, levels = 0, depth = 0, error = false;
        memset(variable, 0, sizeof(variable));
        for(int j = 0; j < line; ++j){
            gets(codes);
            if(error) continue;
            if(codes[0] == 'F'){
                ++iters, ++depth;
                if(variable[codes[2] - 'a'] == 1){
                    printf("%s\n", "ERR");
                    error = true;
                }
                else if(variable[codes[2] - 'a'] == 0) {
                    variable[codes[2] - 'a'] = 1;
                    active.push(codes[2]);
                }
                if(codes[4] != 'n' && codes[strlen(codes) - 1] == 'n' && !fake){
                    levels = max(levels, depth);
                    valid.push(1);
                    inverse.push(0);
                }
                else if(codes[4] == 'n' && codes[strlen(codes) - 1] != 'n'){
                    fake = true;
                    --depth;
                    valid.push(0);
                    inverse.push(1);
                }
                else{
                    --depth;
                    valid.push(0);
                    inverse.push(0);
                }
                
            }
            else if(codes[0] == 'E'){
                if(iters == 0) {
                    printf("ERR\n");
                    error = true;
                }
                else{
                    --iters;
                    if(valid.top() == 1){
                        --depth;
                    }
                    valid.pop();
                    variable[active.top() - 'a'] = 0;
                    active.pop();
                    if(inverse.top() == 1){
                        fake = false;
                    }
                    inverse.pop();
                }
            }
        }
        printf("%d hhh", levels);
        if(iters != 0 && !error) printf("ERR\n");
        else if(!error){
            if(complexity[2] == '1'){
                if(levels == 0) printf("Yes\n");
                else printf("No\n");
            }
            else if(complexity[2] == 'n'){
                if(strlen(complexity) == 6){
                    if(levels == complexity[4]-'0') printf("Yes\n");
                    else printf("No\n");
                }
                else if(strlen(complexity) == 7){
                    char digit[2];
                    digit[0] = complexity[4];
                    digit[1] = complexity[5];
                    //printf("hhh %d", atoi(digit));
                    if(levels == atoi(digit)) printf("Yes\n");
                    else printf("No\n");
                }
            }
        }
    }
    return 0;
}