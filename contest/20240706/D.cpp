#include <cstdio>
int n=0,a[1000000];
unsigned long long b[1000000];
inline void solve(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    for (int i=0;i<n;i++)
        scanf("%lld",b+i);
    printf("%lld",(b[1]-a[1])/a[0]);
}
int main(){
    solve();
}