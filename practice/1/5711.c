#include <stdio.h>
int main(){
    char c;        
    int a = 0;
    while ((c = getchar()) >= '0' && c <= '9')
    {
        a = (a << 3) + ( a << 1 ) + c - '0';
    }
    if ((a%4==0&&a%100!=0)||a%400==0)printf("1");
    else printf("0");
}