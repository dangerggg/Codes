#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

void extend_gcd(int a, int b, int &x, int &y){
    if(b == 0) {
        x = 1, y = 0;
        return;
    }
    extend_gcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a/b) * y;
}

int main(){
    ll a = 0, b = 0;
    scanf("%d%d", &a, &b);
    printf("%lld", a*b-a-b);
    return 0;
}