#include <stdio.h>
int n,m,k,mod=1000000007,
dp[151][151][21][21];//已下白 已下黑 白-黑最大 黑-白最大
inline int min(const int a,const int b){
    if (a<b)return a;else return b;
}
inline int max(const int a,const int b){
    if (a>b)return a;else return b;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
    dp[0][0][0][0]=1;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            for (int x=0;x<=min(i,k);++x)
                for (int y=0;y<=min(j,k);++y){
                    if (i!=n&&x!=k) dp[i+1][j][x+1][max(0,y-1)]=(dp[i][j][x][y]+dp[i+1][j][x+1][max(0,y-1)])%mod;
                    if (j!=m&&y!=k) dp[i][j+1][max(0,x-1)][y+1]=(dp[i][j][x][y]+dp[i][j+1][max(0,x-1)][y+1])%mod;
                }
    int ans=0;
    for (int i=0;i<=min(n,k);++i)
        for (int j=0;j<=min(m,k);++j)
            ans=(ans+dp[n][m][i][j])%mod;
    printf("%d",ans);
}