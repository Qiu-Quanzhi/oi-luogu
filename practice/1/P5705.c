#include <stdio.h>
int main(){
	char a[6],l;
	scanf("%s",a);
	for (;a[l];l++);
	do{
		printf("%c",a[--l]);
	}while(l>0);
}