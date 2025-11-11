#include<stdio.h>
int main(){
int a,b,c;
c=(a=5,b=10,a+b); //Comma operator
printf("c=%d\n",c);
return 0;
}
