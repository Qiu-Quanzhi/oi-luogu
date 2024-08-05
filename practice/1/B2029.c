#include <stdio.h>
int main(){
	short h,r;
	scanf("%hd%hd",&h,&r);
	printf("%.0f",20000/(h*r*r*3.14)+1);
}