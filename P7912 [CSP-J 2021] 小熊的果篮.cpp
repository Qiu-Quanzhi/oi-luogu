#include <cstdio>
#include <queue>
using namespace std;
queue<int> a,b;
int tmp,temp;
void input(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        if(tmp) a.push(i);
        else b.push(i);
    }
    
}
void solve(){
    tmp=0;
    while(!a.empty()&&!b.empty()){

        if (a.front()<b.front()&&a.front()>tmp){
            temp=tmp=a.front();a.pop();
            while(!a.empty()&&a.front()>tmp&&a.front()<b.front()){
                a.push(tmp=a.front());a.pop();
            }
            printf("%d ",temp);
        }else if(b.front()<a.front()&&b.front()>tmp){
            temp=b.front();b.pop();
            while(!b.empty()&&b.front()>tmp&&b.front()<a.front()){
                b.push(tmp=b.front());b.pop();
            }
            printf("%d ",temp);
        }
        else{
            if(a.front()>tmp){
                printf("%d ",a.front());a.pop();
                while(!a.empty()&&a.front()>tmp){
                    a.push(a.front());a.pop();
                }
            }else{
                printf("%d ",b.front());b.pop();
                while(!b.empty()&&b.front()>tmp){
                    b.push(b.front());b.pop();
                }
            }
            tmp=0;
        }
    }
    while(!a.empty()){
        printf("%d\n",a.front());a.pop();
    }
    while(!b.empty()){
        printf("%d\n",b.front());b.pop();
    }
}
int main(){
    input();
    solve();
}