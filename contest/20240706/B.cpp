#include <cstdio>
int n,a[2000000],ans;
inline void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i]&1)a[i]=a[i+n]=1;
        else a[i]=a[i+n]=-1;
    }
}
// void dbg(){
//     for (int i=0;i<2*n+1;i++){
        
//     }
// }
inline void solve(){
    for (int i=2;i<2*n+1;i++){
        a[i]=a[i-1]+a[i];
    }
    // dbg();
    for (int i=0;i<n;i++)
        for (int j=1;j<=n;j++)
            if (a[i]==a[i+j])ans++;
    printf("%d",ans);
}
int main(){
    init();
    solve();
}