#include <iostream>
#include <cmath>
#include <cstdio>
#define mmin(a,b) ((a)<=(b)?(a):(b))
#define mmax(a,b) ((a)>=(b)?(a):(b))
using namespace std;
const int N=1000000;
struct RMQ_ST {
    /**
     *变量的意思分别是：
     *待查数组，存区间最大值数组，存区间最小值数组，最小值，最大值
     */
    int num[N],f1[N][100],f2[N][100],rmin,rmax;
    /**用st预处理num数组*/
    void st_preHandler(int n) {
        int k=(int)(log((double)n)/log(2.0)),m;
        for(int i=0;i<n;i++) f1[i][0]=f2[i][0]=num[i];
        for(int j=1;j<=k;j++)
            for(int i=0;i+(1<<j)-1<n;i++){
                m=i+(1<<(j-1));
                f1[i][j]=mmax(f1[i][j-1],f1[m][j-1]);
                f2[i][j]=mmin(f2[i][j-1],f2[m][j-1]);
            }
    }
    /**对[i,j]区间进行查询*/
    void rmq(int i,int j) {
        int k=(int)(log((double)(j-i+1))/log(2.0));
        rmax=mmax(f1[i][k],f1[j-(1<<k)+1][k]);
        rmin=mmin(f2[i][k],f2[j-(1<<k)+1][k]);
    }
}rmq;
int main() {return 0;}
