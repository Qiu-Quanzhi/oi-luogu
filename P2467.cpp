#include <cstdio>
int n,p;const int N=4200;
int dp[N][N];
inline void init(){
    scanf("%d%d",&n,&p);
}
inline void solve(){
    for (int i=0;i<n;i++)
        dp[0][i][1]=dp[n-1][i]
}
int main(){
    init();
    solve();
}