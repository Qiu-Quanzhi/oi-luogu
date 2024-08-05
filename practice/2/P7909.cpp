#include <iostream>
using namespace std;
int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    if (l/n==r/n)
        printf("%d",r%n);
    else
        printf("%d",n-1);
}