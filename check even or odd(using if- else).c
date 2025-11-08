#include<stdio.h>
int main(){
    int num;
    printf("enter a number:");
    scanf("%d,&num");//use & before num
    if(num%2==0)
        printf("%d is even.",num);
    printf("%d s odd",num);
    return 0;
}
