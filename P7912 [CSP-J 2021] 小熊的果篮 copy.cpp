#include <cstdio>
using namespace std;
struct block
{
    int a,b,t;
    block *pre,*nxt;
} sta[200001];
int n;
void input(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        sta[i]={i,i+1,x,sta+i-1,sta+i+1};
    }
    sta[0].pre=NULL;
    sta[1].nxt=sta+1;
    sta[1].pre=sta;
    sta[n].nxt=NULL;
}
void merge(block &a){
    a.b=a.nxt->b;
    a.nxt=a.nxt->nxt;
    a.nxt->pre=&a;
}
void del(block &a){
    if (a.pre!=NULL)
        a.pre->nxt=a.nxt;
    if (a.nxt!=NULL){
        a.nxt->pre=a.pre;
        merge(*a.pre);
    }
}
void init(){
    block *p=sta+1;
    while (p->nxt!=NULL){
        if (p->t==p->nxt->t)
            merge(*p);
        p=p->nxt;
    }
}
void solve(){
    block *p;
    while((p=sta->nxt)!=NULL){
        while(p!=NULL){
            printf("%d ",p->a);
        }
    }
}