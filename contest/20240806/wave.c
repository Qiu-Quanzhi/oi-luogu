#include <stdio.h>
int n,a[100000],b[100000],c1,c2;
signed main(){
    freopen("wave.in","r",stdin);
    freopen("wave.out","w",stdout);
    scanf("%d",&n);
    if (n<3){printf("0");return 0;}
    for (int i=0;i<n;i++)scanf("%d",a+i);
    for (int i=1,f=1;i<n;i++,f=-f){
        b[i]=a[i];
        if (f>0&&a[i]<=a[i-1])
            c1++,a[i]=0x6fffffff;
        else if(f<0&&a[i]>=a[i-1])
            c1++,a[i]=0;
        if (f<0&&b[i]<=b[i-1])
            c2++,b[i]=0x6fffffff;
        else if(f>0&&b[i]>=b[i-1])
            c2++,b[i]=0;
    }
    if (c1<c2)printf("%d",c1);else printf("%d",c2);
}