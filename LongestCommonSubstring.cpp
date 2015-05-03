#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 1000;
char a[maxn],b[maxn];
int dp[maxn][maxn] = {0};
void reserve(int n) {for(int i = 0; i < n; i++) b[n-i-1] = a[i];}
int lcs(int la,int lb)
{
    for(int i = 1; i <= la; i++)
            for(int j = 1; j <= lb; j++)
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = dp[i][j-1] >= dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];
    return dp[la][lb];
}
int main() {return 0;}
