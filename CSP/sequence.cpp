#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n = 0;
    float midone = 0;
    cin >> n;
    int sequence[n];
    for (int i = 0; i < n; ++i) cin >> sequence[i];
    
    if (n % 2 == 0) midone = sequence[n/2];
    else {
        midone = sequence[(n+1)/2] + sequence[(n-1)/2];
        midone = midone / 2;
    }
    if (sequence[0] < sequence[n-1]){
        cout << sequence[n-1] << ' ' ;
        cout << midone << setprecision(1);
        cout << ' ' << sequence[0] << endl;
    } else{
        cout << sequence[0] << ' ' ;
        cout << midone << setprecision(1);
        cout << ' ' << sequence[n-1] << endl;
    }
    return 0;
}