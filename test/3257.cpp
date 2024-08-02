#include <iostream>
namespace oi{
    void init();
    void solve();
    void optimize_io();
}
namespace SA{
    void init(){
        
    }
}
int main(){
    oi::init();
    oi::solve();
}
namespace oi
{
    const int N=5e5+1;
    int n,m,t;
    char str[N];
    void init(){
        oi::optimize_io();
        std::cin>>n>>m>>str;
        for (int i=0;i<m;i++){
            std::cin>>t;
            int q[t];
            for (auto &i:q)
                std::cin>>i;
            
        }
    }
    auto solve(int *begin,int *end){
        
    }
}
