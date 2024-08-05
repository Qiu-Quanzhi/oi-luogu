#include<iostream>
#include<algorithm>
int main(){
    int n;
    std::cin>>n;
    int a[n];
    for (auto &i:a)
        std::cin>>i;
    std::sort(a,a+n);
    for (auto &&i:a)
        std::cout<<i<<" ";
}