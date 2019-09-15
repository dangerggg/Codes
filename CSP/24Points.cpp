#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

int main(){
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    stack <int> comp;
    int n = 0, size = 0;
    string formula;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> formula;
        size = formula.size();
        for(int j = 0; j < size; ++j){
            if (formula[j] == '*'){
                
            }
        }
    }
    return 0;
}