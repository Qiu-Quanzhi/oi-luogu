#include <cstdio>
const int N=300000;int n;
char a[N+1];
long double f[N+1],x[N+1];
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	for (int i=0;i<n;i++){
		switch(a[i]){
			case 'o':
				x[i+1]=x[i]+1;
				f[i+1]=f[i]+x[i]*2+1;
				break;
			case 'x':
				x[i+1]=0;
				f[i+1]=f[i];
				break;
			case '?':
				x[i+1]=(x[i]+1)*0.5;
				f[i+1]=f[i]+(x[i]*2+1)*0.5;
		}
	}
	printf("%.4Lf",f[n]);
}