#include <iostream>
#include <algorithm>
const int N=1e6;
namespace LT{
    struct node
    {
        int fa;
        int val,dist,l,r;
    }t[N];int tot=1;
    void init(){t[0].dist=-1;}
    int merge(int a,int b){
        if (!a||!b)return a|b; //合并空集处理
        if (t[a].val>t[b].val)std::swap(a,b);
        t[t[a].r=merge(t[a].r,b)].fa=a;
        if (t[t[a].l].dist<t[t[a].r].dist)
            std::swap(t[a].l,t[a].r);
        t[a].dist=t[t[a].r].dist+1;
        return a;
    }
    int new_node(int x){t[tot].val=x;return tot++;}
    void insert(int &a,int x){
        a=merge(a,new_node(x));
    }
}
namespace oi{
    int n,m;
    void optimize_io(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    void solve(){
        int op,x,y;
        std::cin>>op;
        if (--op){

        }else{
            
        }
    }
    void init(){
        LT::init();
        std::cin>>n>>m;
        for (int i=0,t;i<n;i++){
            std::cin>>t;
            LT::new_node(t);
        }
        for (int i=0;i<m;i++)
            solve();
    }
}
int main(){

}