#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**需要模的数*/
const int mod = 9901;
long long quickPower(long long x,long long y) {
    long long result=1;
    while(y) {
        if(y&1) {
            result*=x;
            result%=mod;
        }
        y>>=1;x*=x;
    }
    return result%mod;
}
int main() {return 0;}
