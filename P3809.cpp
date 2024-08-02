#include <iostream>
#include <cstring>
#include <algorithm>
const int N=2e6;
int n;char str[N];
namespace SA{
    unsigned long long sa[N<<1],rk[N<<1],height[N];
    int rkn;
    void display(unsigned long long sa[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<sa[i]<<" ";
        std::cout<<"\n";
    }
    void display_decode(unsigned long long sa[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<((sa[i]&0xffffffff00000000)>>32)<<"|"<<(sa[i]&0xffffffff)<<" ";
        std::cout<<"\n";
    }
    void transition(){
        for (int i=0;i<n;i++)
            rk[sa[i]]=i+1;
    }
    bool rank(){
        std::copy(sa,sa+n,rk);
        SA::display_decode(rk);
        std::sort(rk,rk+n);
        SA::display_decode(rk);
        rkn=std::unique(rk,rk+n)-rk;
        for (int i=0;i<n;i++)
            sa[i]=std::lower_bound(rk,rk+rkn,sa[i])-rk;
        SA::display();
        return rkn==n;
    }
    void initSA(){
        n=std::strlen(str);
        std::copy(str,str+n,sa);
        if (SA::rank())return;
        for (int j=1;j<n;j<<=1){
            for (int i=0;i<n;i++)
                sa[i]=(sa[i]<<32)|sa[i+j];
            if (SA::rank())return;
        }
        SA::transition();
        SA::display();
    }
    void initHeight(){
        int k=0;
    for (int i=0;i<n;++i){
        if (rk[i]==1)continue;
        if (k) --k;//h[i] >= h[i - 1] - 1;
        int j = sa[rk[i] - 1];
        while (j + k <= n && i + k <= n && str[i + k] == str[j + k]) ++k;
        height[rk[i]] = k;
    }
    }
}
namespace oi{
    void optimize_io(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    void init(){
        // oi::optimize_io();
        std::cin>>str;
    }
    void solve(){
        SA::initSA();
        // SA::initHeight();
        SA::display(SA::rk);
    }
}
int main(){
    oi::init();
    oi::solve();
}