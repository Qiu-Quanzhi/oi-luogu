#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const long double eps=1e-8;
long double m[100][101],x[100];int n;
void init(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<=n;j++)
			scanf("%Lf",&m[i][j]);
}
//void dbg(){
//	for (int i=0;i<n;i++){
//		for (int j=0;j<=n;j++)
//			printf("\t%Lf",m[i][j]);
//		printf("\n");
//	}
//		printf("\n");
//}
void T(int a,int b){
	for (int i=0;i<=n;i++)
		swap(m[a][i],m[b][i]);
}
void T(int a,int b,long double k){
	for (int i=0;i<=n;i++)
		m[a][i]+=m[b][i]*k;
}
void Gause(){
	for (int i=0;i<n;i++){
		int r=i;
		for (int j=i+1;j<n;j++){
			if (fabs(m[j][i])>fabs(m[r][i]))
				r=j;
		}
		if (fabs(m[r][i])<eps){
			printf("No Solution");
			return;
		}
		if (r!=i)T(r,i);
		for (int j=i+1;j<n;j++)
			T(j,i,-m[j][i]/m[i][i]);
	}
	for (int i=n-1;i>=0;i--){
		x[i]=m[i][n];
		for (int j=i+1;j<n;j++)
			x[i]-=m[i][j]*x[j];
		x[i]/=m[i][i];
	}
	for (int i=0;i<n;i++)
		printf("%.2Lf\n",x[i]);
}
int main(){
	init();
	Gause();
}