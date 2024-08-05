#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
long double P,p[500001];
vector<int> l[500000];
void add(int a,long double &x){
	for (;a<=n;a+=a&-a)
		p[a]+=x;
}
long double query(int a){
	long double ans=0;
	for (;a;a-=a&-a)
		ans+=p[a];
	return ans;
}
void init(){
	scanf("%d%d%Lf",&n,&m,&P);
	for (int i=0,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		l[a-1].push_back(b-1);
	}
}
void solve(){
	long double ans=0;
	for (int i=0,k;i<n;i++){
		k=l[i].size();
		sort(l[i].begin(),l[i].end());
		long double p=P/(1-pow(1-P,k));
		for (int j=0;j<k;j++,p*=1-P)
			ans+=p*query(n-l[i][j]);
		p=P/(1-pow(1-P,k));
		for (int j=0;j<k;j++,p*=1-P)
			add(n-l[i][j]+1,p);
	}
	printf("%.2Lf",ans);
}
int main(){
	init();
	solve();
} 