#include <stdio.h>
int main(){
	int s,v;
	scanf("%d%d",&s,&v);
	int t=470-(s%v?s/v+1:s/v);
	if (t<0)t+=1440;
	printf("%02d:%02d",t/60,t%60);
}