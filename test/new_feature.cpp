#include <iostream>
#include <set>
namespace oi{
    std::multiset<int> a;
    void optimize_io(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    void init(){
        oi::optimize_io();
        int n;
        std::cin>>n;
        for (int i=0,tmp;i<n;i++)
            std::cin>>tmp,a.insert(tmp);
    }
    void solve(){
        for (auto &&i : a)
            std::cout<<i<<" ";
    }
}
int main(){
    oi::init();
    oi::solve();
}