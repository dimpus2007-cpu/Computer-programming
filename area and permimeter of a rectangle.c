#include<stdio.h>
int main(){
    float lenght,breadth,area,perimeter;
    printf("enter lenght and breadth:");
    scanf("%f%f",&lenght,&breadth);
    area= lenght*breadth;
    perimeter=2*(lenght+breadth);
    printf("Area=%2f\n perimeter =%2f",area,perimeter);
    return 0;
}
