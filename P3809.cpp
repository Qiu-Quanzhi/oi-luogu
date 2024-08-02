#include <iostream>
#include <cstring>
#include <algorithm>
const int N=2e6;
int n;char a[N];
namespace SA{
    unsigned long long sa[N<<1],tmp[N<<1];
    int tmpn;
    void display(unsigned long long sa[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<sa[i]<<" ";
        std::cout<<"\n";
    }
    // void display_decode(unsigned long long sa[]=sa){
    //     for (int i=0;i<n;i++)
    //         std::cout<<((sa[i]&0xffffffff00000000)>>32)<<"|"<<(sa[i]&0xffffffff)<<" ";
    //     std::cout<<"\n";
    // }
    void transition(){
        for (int i=0;i<n;i++)
            tmp[sa[i]]=i+1;
    }
    bool rank(){
        std::copy(sa,sa+n,tmp);
        std::sort(tmp,tmp+n);
        tmpn=std::unique(tmp,tmp+n)-tmp;
        for (int i=0;i<n;i++)
            sa[i]=std::lower_bound(tmp,tmp+tmpn,sa[i])-tmp;
        return tmpn==n;
    }
    void init(){
        n=std::strlen(a);
        for (int i=0;i<n;i++)
            sa[i]=a[i];
        if (SA::rank())return;
        for (int j=1;j<n;j<<=1){
            for (int i=0;i<n;i++)
                sa[i]=(sa[i]<<32)|sa[i+j];
            if (SA::rank())return;
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
        oi::optimize_io();
        std::cin>>a;
    }
    void solve(){
        SA::init();
        SA::transition();
        SA::display(SA::tmp);
    }
}
int main(){
    oi::init();
    oi::solve();
}