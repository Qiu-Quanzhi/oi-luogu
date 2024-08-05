#include <cstdio>
int n;long long m;
int a[200000];
int min=0xffffffff;

int sum=0
,max=0
;
void init(){
    int cost[1000000000];
    for (int i=0;i<n;i++)
        cost[a[i]]++;
    long long spare=sum-m;
    int i=1,j;
        for (;!cost[i];i++);
    while(1){
        j=i;
        for (i++;!cost[i];i++);
        if (spare/cost[j]+j<i){
            printf("%lld",spare/cost[j]+j);
            return;
        }
        else{
            // printf(" %d\n",j);
            cost[i]+=cost[j];spare-=spare/cost[j]*j;
    }}
}
int main(){
    scanf("%d%lld",&n,&m);
    for (int i=0;i<n;sum+=a[i++]){
        if (a[i]>max)max=a[i];
        scanf("%d",a+i);
    }
    if (sum<=m){
        printf("infinite");
        return 0;
    }
    init();
}