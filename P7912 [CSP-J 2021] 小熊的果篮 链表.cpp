#include <cstdio>
using namespace std;
struct block{
    int a, b, t; block *pre, *nxt;
} sta[200001];
bool vis[200001]; int n;
void input(){
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        sta[i] = {i, i + 1, x, sta + i - 1, sta + i + 1};
    }
}
void merge(block &a){
    a.b = a.nxt->b; a.nxt = a.nxt->nxt;
    if (a.nxt != NULL) a.nxt->pre = &a;
}
void del(block &a){
    if (a.pre != NULL)
        a.pre->nxt = a.nxt;
    if (a.nxt != NULL && (a.nxt->pre = a.pre) != sta)
        merge(*a.pre);
}
void init(){
    sta[0].pre = NULL;
    sta[n].nxt = NULL;
    sta[0].nxt = sta + 1;
    sta[1].pre = sta;
    block *p = sta;
    int cnt = 0;
    while ((p = p->nxt) != NULL) while (p->nxt != NULL && p->t == p->nxt->t)
            merge(*p);
}
void solve(){
    block *p;
    while ((p = sta) && p->nxt != NULL){
        while ((p = p->nxt) != NULL){
            while (vis[p->a])
                p->a++;
            printf("%d ", p->a);
            vis[p->a++] = true;
            if (p->a == p->b)
                del(*p);
        }
        printf("\n");
    }
}
int main(){
    input();
    init();
    solve();
}