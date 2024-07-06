#include <cstdio>
#include <set>
using namespace std;
struct node{
    int ch[200],n;
    bool s,ss;
};
node a[300001];
int n,k;
set<int> ans;
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
set<int> dfs1(int x){
    set<int> b;b.insert(x);
    if (!a[x].n)return b;
    for (int i=0,cnt=0;i<a[x].n;i++){
        auto c=dfs1(a[x].ch[i]);
        if (a[a[x].ch[i]].s)cnt++;
        if(cnt>1)a[x].ss=true;
        b.insert(c.begin(),c.end());
    }
    if (check(b))a[x].s=true;
    return b;
}
void dfs2(int x){
    if (!a[x].s)return;
    ans.insert(x);
    if (a[x].ss)return;
    for (int i=0;i<a[x].n;i++)
        dfs2(a[x].ch[i]);
}
void solve(){
    dfs1(a[0].ch[0]);
    // for (int i=0;i<=n;i++){
    //     printf ("%d ",a[i].s);
    // }
    dfs2(a[0].ch[0]);
    for(auto i=ans.begin();i!=ans.end();i++)
        printf("%d ",*i);
}
int main(){
    input();
    solve();
}