#include <cstdio>
int a[101];
int main(){
    int n;
    scanf("%d",&n);
    int i=1,f=0,s=0;
    for (;i<=n;i++){
        scanf("%d",a+i);
        if (a[i]>a[f]){
            s=f;f=i;
        }else
            if (a[i]>a[s])
                s=i;
    }
    printf("%d",s);
}