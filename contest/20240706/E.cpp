#include <cstdio>
#include <cmath>
int n,q;
int a[100000],b[100000],x[100000],c[100000];
inline void input(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d%d",a+i,b+i);
    for(int i=0;i<q;i++)
        scanf("%d",x+i);
}
inline void init(){
    for(int i=0;i<n;i++)
        if (a[i])
            c[i]=floor(-1.*b[i]/a[i]);
        else
            c[i]=b[i]>0?0x80000000:0x7fffffff;
}
inline void solve(){
    for (int i=0,ans=0;i<q;i++,printf("%d\n",ans),ans=0)
        for (int j=0;j<n;j++)
        // ;printf("%d %d %d %d\n",x[i],c[j],j,ans),
            if (x[i]>c[j])
                ans^=j+1;
}
int main(){
    input();
    init();
    solve();
}