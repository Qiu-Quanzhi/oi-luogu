#include <cstdio>
#include <set>
using namespace std;
struct node{
    int fa;
    int ch[100000],n;
    bool s;
};
node a[300001];
int n,k;
int abs(int x){
    if (x<0)return -x;
    return x;
}
void input(){
    scanf("%d%d",&n,&k);
    for (int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
        a[tmp].ch[a[tmp].n++]=i;
    }
}
bool check(set<int>& t){
    int l=*t.begin();auto i=t.begin();i++;
    for (;i!=t.end();l=*(i++))
        if (abs(*i-l)<=k)
            return true;
     return false;
}
set<int> dfs(int x){
    set<int> b;b.insert(x);
    if (!a[x].n)return b;
    for (int i=0;i<a[x].n;i++){
        auto c=dfs(a[x].ch[i]);
        b.insert(c.begin(),c.end());
    }
    if (check(b))a[x].s=true;
    return b;
}
void solve(){
    dfs(0);
    for (int i=0;i<=n;i++){
        printf ("%d ",a[i].s);
    }
}
int main(){
    input();
    //solve();
}
