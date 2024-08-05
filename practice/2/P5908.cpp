#include <iostream>
using namespace std;
int n,d,cnt,ans=-1;
struct node{
    node **pos;
    node *nxt;
};
node *head[100001],edge[200000];
inline void add(int u,int v){
    edge[cnt].nxt=head[u];
    head[u]=&edge[cnt];
    edge[cnt++].pos=&head[v];
}
inline void init(){
    cin>>n>>d;
    for (int i=1,u,v;i<n;i++){
        cin>>u>>v;
        add(u,v);add(v,u);
    }
}
void dfs(node *&u,node *&f,int dis){
    ans++;
    if (dis++==d)return;
    for (node *i=u;i;i=i->nxt)
        if (*i->pos!=f)
            dfs(*i->pos,u,dis);
}
inline void solve(){
    dfs(head[1],head[0],0);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}