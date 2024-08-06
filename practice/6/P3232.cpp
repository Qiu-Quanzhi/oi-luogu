#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int h[500],tot=1,n,c,deg[500];const long double eps=1e-8;
long double m[499][500],x[500],ee[125000];
void T(int a,int b){
	for (int i=0;i<=n;i++)
		swap(m[a][i],m[b][i]);
}
void T(int a,int b,long double k){
	for (int i=0;i<=n;i++)
		m[a][i]+=m[b][i]*k;
}
void dbg(){
	for (int i=0;i<n;i++){
		for (int j=0;j<=n;j++)
			printf("\t%Lf",m[i][j]);
		printf("\n");
	}
		printf("\n");
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
}
struct edge{
	int to,nxt;
} e[250001];
void add(int u,int v){
	e[tot].nxt=h[u];
	e[tot].to=v;
	h[u]=tot++;
	deg[u]++;
}
void link(int a,int b){
	add(a,b);
	add(b,a);
}
void init(){
	scanf("%d%d",&n,&c);
	for (int i=0,u,v;i<c;i++){
		scanf("%d%d",&u,&v);
		link(u-1,v-1);
	}
}
void solve(){
	for (int i=0;i<n-1;i++){
		m[i][i]=-1;
		for (int j=h[i];j;j=e[j].nxt){
			if (e[j].to!=n-1)
				m[i][e[j].to]=1.0/deg[e[j].to];
		}
	}
	m[0][--n]=-1;
	Gause();n++,tot=0;
	for (int i=0;i<n;i++)
		for (int j=h[i];j;j=e[j].nxt){
			if (j&1)continue;
			ee[tot++]=x[i]/deg[i]+x[e[j].to]/deg[e[j].to];
		}
	sort(ee,ee+c);
	long double ans=0;
	for (int i=0;i<c;i++)
		ans+=ee[i]*(c-i);
	printf("%.3Lf",ans);
}

int main(){
	init();
	solve();
}