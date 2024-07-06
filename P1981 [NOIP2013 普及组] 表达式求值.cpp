#include <cstdio>
int main(){
    int a=0,b=1,c;
    char op;
    for(;;){
        scanf("%d",&c);
        scanf("%c",&op);
        b*=(c%10000);
        b%=10000;
        if(op!='*'){
            a+=b;
            a%=10000;
            b=1;
            if(op!='+')
                break;
        }
    }
    printf("%d",a);
}