#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 
//CJKC https://www.luogu.com.cn/article/pytvbmj3
int w,n,ny,dp[100000],BIT[100001],
// tmpx[100000],
tmpy[100000];
struct pie{
	int t,p,v,x,y;
}a[100000];
bool cmpx(pie a,pie b){
	return a.x<b.x;
}
bool cmpy(pie a,pie b){
	return a.y<b.y;
}
void add(int a,int x){
	for (++a;a<=ny;a+=a&-a)
		BIT[a]=max(BIT[a],x);
}
int query(int a){
	int res=0;
	for (++a;a;a-=a&-a)
		res=max(BIT[a],res);
	return res;
}
void init(){
	scanf("%d%d",&w,&n);
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&a[i].t,&a[i].p,&a[i].v);
		// tmpx[i]=
		a[i].x=2*a[i].t-a[i].p;
		tmpy[i]=a[i].y=2*a[i].t+a[i].p;
	}
}
void solve(){
	sort(a,a+n,cmpx);
	// sort(tmpx,tmpx+n);
	sort(tmpy,tmpy+n);
	ny=unique(tmpy,tmpy+n)-tmpy;
	for(int i=0;i<n;i++){
		a[i].y=lower_bound(tmpy,tmpy+ny,a[i].y)-tmpy; //LISJ
		// printf("$LISJ: %d\n",a[i].y);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=query(a[i].y)+a[i].v;
		add(a[i].y,dp[i]);
		ans=max(ans,dp[i]);//ERWWPMXU
	}
	printf("%d",ans);
}
int main(){
	init();
	solve();
}