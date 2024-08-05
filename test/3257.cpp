#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <set>
const int N=2e6;
int n;char str[N];
template <typename T>
class SparseTable {
    using VT=std::vector<T>;
    using VVT=std::vector<VT>;
    using func_type=std::function<T(const T &,const T &)>;
    VVT ST;
    static T default_func(const T &t1,const T &t2){return std::min(t1, t2);}
    func_type op;
    public:
        SparseTable(const std::vector<T> &v,func_type _func=default_func) {
            op=_func;
            int len=v.size(),l1=ceil(log2(len))+1;
            ST.assign(len,VT(l1,0));
            for (int i=0;i<len;++i)
                ST[i][0]=v[i];
            for (int j=1;j<l1; ++j) {
                int pj=(1<<(j-1));
                for (int i=0;i+pj<len;++i) 
                    ST[i][j]=op(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
            }
        }
        T query(int l,int r) {
            int lt=r-l+1,q=floor(std::log2(lt));
            return op(ST[l][q], ST[r-(1<<q)+1][q]);
        }

};
namespace SA{
    typedef unsigned long long T;
    T sa[N<<1],rk[N<<1];
    std::vector<T> height;
    int rkn;
    void display(T a[]=SA::sa){
        for (int i=0;i<n;i++)
            std::cout<<a[i]<<" ";
        std::cout<<"\n";
    }
    void display(std::vector<T> a=SA::height){
        for (auto &&i:a)
            std::cout<<i<<" ";
        std::cout<<"\n";
    }
    void display_index(T b[]=SA::rk,std::vector<T> a=SA::height){
        for (int i=0;i<n;i++)
            std::cout<<a[b[i]]<<" ";
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
        // n=std::strlen(str);
        std::copy(str,str+n,sa);
        if (SA::rank())return;
        for (int j=1;j<n;j<<=1){
            for (int i=0;i<n;i++)
                sa[i]=(sa[i]<<32)|sa[i+j];
            if (SA::rank())return;
        }
    }
    void initHeight(){
        height.resize(n);
        for (int i=0,k=0;i<n;++i) {
            if (rk[i]==0)continue;
            if (k)--k;
            while (str[i+k]==str[sa[rk[i]-1]+k])++k;
            height[rk[i]]=k;
        }
    }
    SparseTable<T> getHeightST(){
        SparseTable<T> heightST(height);
        return heightST;
    }
}
namespace oi{
    int m;const long long mod=23333333333333333;
    void optimize_io(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    void init(){
        oi::optimize_io();
        // char test_str[]="aabaaaab";
        // std::strcpy(str,test_str);
        std::cin>>n>>m>>str;
    }
    void solve(){
        SA::initSA();
        SA::transition();
        SA::initHeight();
        // SA::display(SA::rk);
        // SA::display(SA::height);
        SparseTable<SA::T> heightST=SA::getHeightST();
        long long ans=0;
        for (int i=0,qn,t,tt,q[2000];i<m;i++,ans=0){
            std::cin>>t;
            for (int j=0;j<t;q[j++]=SA::rk[tt-1])
                std::cin>>tt;
            std::sort(q,q+t);
            qn=std::unique(q,q+t)-q;
            for (int j=0;j<qn-1;j++)
                for (int l=j+1;l<qn;l++)
                    ans+=heightST.query(q[j]+1,q[l]),ans%=mod;
            std::cout<<ans<<"\n";
        }
    }
}
int main(){
    oi::init();
    oi::solve();
}