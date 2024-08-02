#include<bits/stdc++.h>
using namespace std;
#define N 203
#define ll long long
int n,m,s,t,x,y,z,q[N],h[N],b[N][N],d[N],c[N];
long long ans;
struct edge{
	int to,nxt;
	long long val;
}e[10003];
bool bfs(){
	memset(d,0,sizeof d);
	q[1]=s,d[s]=1;
	int i=1,j=2;
	while(i<j){
		x=q[i++],c[x]=h[x];
		for(int i=h[x];i;i=e[i].nxt){
			int to=e[i].to;
			if(!d[to]&&e[i].val)q[j++]=to,d[to]=d[x]+1;
		}
	}
	return d[t];
}
ll dfs(int x,ll l){
	if(x==t)return l;
	for(int i=c[x];i;i=e[i].nxt,c[x]=i){
        printf("%d %d\n",i<<2,int(bool(i)<<1));
		cout<<i<<' '<<(bool)i<<' '<<(bool)0<<'\n';
		y=e[i].to;
		if(d[y]!=d[x]+1||!e[i].val)continue;
		z=dfs(y,min(l,e[i].val));
		if(z){
			e[i].val-=z,e[i^1].val+=z;
			return z;
		}
	}
	// return 0;
}
int main(){
//	ios::sync_with_stdio(0);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(b[x][y])e[b[x][y]].val+=z;
		else{
			b[x][y]=2*i,e[2*i]={y,h[x],z},h[x]=2*i;
			e[2*i+1]={x,h[y]},h[y]=2*i+1;
		}
	}
	while(bfs()){
		while(z=dfs(s,1e18))ans+=z;
	}
	cout<<ans;
}
/*
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30
*/