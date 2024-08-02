#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
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
            rk[sa[i]]=i;
    }
    bool rank(){
        std::copy(sa,sa+n,rk);
        std::sort(rk,rk+n);
        rkn=std::unique(rk,rk+n)-rk;
        for (int i=0;i<n;i++)
            sa[i]=std::lower_bound(rk,rk+rkn,sa[i])-rk;
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
    }
    void initHeight(){
        for (int i=0,k=0;i<n;++i) {
            if (rk[i]==0)continue;
            if (k)--k;
            while (str[i + k] == str[sa[rk[i]] + k]) ++k;
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
        char test_str[]="aabaaaab";
        std::strcpy(str,test_str);
        // std::cin>>str;
    }
    void solve(){
        SA::initSA();
        SA::transition();
        SA::initHeight();
        SA::display(SA::sa);
        SA::display(SA::rk);
        SA::display(SA::height);
    }
}
int main(){
    oi::init();
    oi::solve();
}