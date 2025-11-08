#include<stdio.h>
int main(){
float p,r,t,si;
printf("enter principal,rate,time:");
scanf("%f%f%f",&p,&r,&t);
      si=(p*r*t)/100;
printf("simple interest=%2.f",si);
return 0;
}
