#include <cstdio>
int y;
int main(){
    scanf("%d",&y);
    if (y%4==0)
        if (y%100==0)
            if (y%400==0)
                printf("366");
            else
                printf("365");
        else
            printf("366");
    else
        printf("365");
}