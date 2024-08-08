#include <iostream>
#include <cstring>
#include <algorithm>
const int N=2e6;
int n;char str[N];
namespace SA{
    // 定义一个结构体，用于存储后缀数组和排名数组
    unsigned long long sa[N<<1],rk[N<<1],height[N];
    int rkn;
    // 打印后缀数组
    void display(unsigned long long sa[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<sa[i]<<" ";
        std::cout<<"\n";
    }
    // 打印解码后的后缀数组
    void display_decode(unsigned long long sa[]=sa){
        for (int i=0;i<n;i++)
            std::cout<<((sa[i]&0xffffffff00000000)>>32)<<"|"<<(sa[i]&0xffffffff)<<" ";
        std::cout<<"\n";
    }
    // 转换排名数组
    void transition(){
        for (int i=0;i<n;i++)
            rk[sa[i]]=i+1;

    }
    // 排名
    bool rank(){
        std::copy(sa,sa+n,rk);
        std::sort(rk,rk+n);
        rkn=std::unique(rk,rk+n)-rk;
        for (int i=0;i<n;i++)
            sa[i]=std::lower_bound(rk,rk+rkn,sa[i])-rk;
        return rkn==n;
    }
    // 初始化后缀数组
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
    // 初始化高度数组
    void initHeight(){
        int k=0;
        for (int i=0;i<n;++i){
            if (rk[i]==1)continue;
            if (k)--k;//h[i] >= h[i - 1] - 1;
            int j=sa[rk[i]-1];
            while (j+k<=n&&i+k<=n&&str[i+k]==str[j+k])++k;
            height[rk[i]-1]=k;
            
    }
    }
}
namespace oi{
    // 优化输入输出
    void optimize_io(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    // 初始化
    void init(){
        // oi::optimize_io();
        char test_str[]="aabaaaab";
        std::strcpy(str,test_str);
        // std::cin>>str;
    }
    // 解决问题
    void solve(){
        SA::initSA();
        SA::transition();
        // SA::initHeight();
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