#include <iostream>
#include <cmath>
using namespace std;
const double PI=3.141593;
void q1(){
	printf("I love Luogu!");
}
void q2(){
	printf("6 4");
}
void q3(){
	printf("3\n12\n2");
}
void q4(){
	printf("166.667");
}
void q5(){
	printf("15");
}
void q6(){
	cout<<sqrt(117);
}
void q7(){
	printf("110\n90\n0");
}
void q8(){
	cout<<10*PI<<"\n"<<25*PI<<"\n"<<PI*4/3*125;
}
void q9(){
	printf("22");
}
void q10(){
	printf("9");
}
void q11(){
	cout<<100.0/3;
}
void q12(){
	printf("13\nR");
}
void q13(){
	cout<<(int)(pow(PI*4/3*(1064),1.0/3));
}
void q14(){
	printf("50");
}

int main(){
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:
			q1();break;
		case 2:
			q2();break;
		case 3:
			q3();break;
		case 4:
			q4();break;
		case 5:
			q5();break;
		case 6:
			q6();break;
		case 7:
			q7();break;
		case 8:
			q8();break;
		case 9:
			q9();break;
		case 10:
			q10();break;
		case 11:
			q11();break;
		case 12:
			q12();break;
		case 13:
			q13();break;
		case 14:
			q14();break;
	}
}