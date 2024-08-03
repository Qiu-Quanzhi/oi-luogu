#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
const int N=2e6;
int n;char str[N];
namespace SA{
    typedef unsigned long long T;
    T sa[N<<1],rk[N<<1],height[N];
    int rkn;
    void display(T a[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<a[i]<<" ";
        std::cout<<"\n";
    }
    // void display_decode(T sa[]=sa){
    //     for (int i=0;i<n;i++)
    //         std::cout<<((sa[i]&~(int)-1)>>32)<<"|"<<(sa[i]&(int)-1)<<" ";
    //     std::cout<<"\n";
    // }
    void transition(){
        for (int i=0;i<n;i++)
            rk[sa[i]]=i;
        std::swap(rk,sa);
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
            while (str[i+k]==str[sa[rk[i]-1]+k])++k;
            height[rk[i]]=k;
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
        // char test_str[]="aabaaaab";
        // std::strcpy(str,test_str);
        std::cin>>str;
    }
    void solve(){
        SA::initSA();
        SA::transition();
        SA::initHeight();
        SA::display(SA::sa);
        // SA::display(SA::rk);
        SA::display(SA::height);
    }
}
int main(){
    oi::init();
    oi::solve();
}