#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**需要模的数*/
const int mod = 10000;
struct Matrix{
    long long val[2][2];
    /**普通矩阵*/
    Matrix() {val[0][0]=1,val[0][1]=1,val[1][0]=1,val[1][1]=0;}
    /**单位阵*/
    void toUnit() {val[0][0]=1,val[0][1]=0,val[1][0]=0,val[1][1]=1;}
    Matrix& operator*=(const Matrix& another){
        long long a=(val[0][0]*another.val[0][0]+val[0][1]*another.val[1][0])%mod;
        long long b=(val[0][0]*another.val[0][1]+val[0][1]*another.val[1][1])%mod;
        long long c=(val[1][0]*another.val[0][0]+val[1][1]*another.val[1][0])%mod;
        long long d=(val[1][0]*another.val[0][1]+val[1][1]*another.val[1][1])%mod;
        val[0][0]=a,val[0][1]=b,val[1][0]=c,val[1][1]=d;
        return *this;
    }
    long long value() {return val[0][1]%mod;}
};
long long Fibonacci(int n){
    /**第0项为0，第1项为1*/
    if(0==n) return 0;if(1==n) return 1;
    Matrix t,matrix,ret;
    int k=n-1;
    matrix.toUnit();
    while(k) {
        if(k&1) ret*=t;
        k>>=1;t*=t;
    }
    /**matrix中的val[0][0]存F[n+1]的值，val[0][1]和val[1][0]存F[n]的值，val[1][1]存F[n-1]的值*/
    matrix*=ret;
    return matrix.value();
}
int main() {return 0;}
