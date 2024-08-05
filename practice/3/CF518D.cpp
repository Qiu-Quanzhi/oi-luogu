#include <cstdio>
int n,t;
long double p;
int main(){
	long double a[2001][2001]={1};
	scanf("%d%Lf%d",&n,&p,&t);
	for (int i=1;i<=t;i++)
		a[i][0]=a[i-1][0]*(1-p);
	for (int i=1;i<=t;i++)
		for (int j=1;j<=i&&j<=n;j++)
			if (j==n)
				a[i][j]=a[i-1][j]+p*a[i-1][j-1];
			else
				a[i][j]=(1-p)*a[i-1][j]+p*a[i-1][j-1];
	long double ans=0;
	for (int i=1;i<=t;i++)
		ans+=i*a[t][i];
	printf("%.6Lf",ans);
}