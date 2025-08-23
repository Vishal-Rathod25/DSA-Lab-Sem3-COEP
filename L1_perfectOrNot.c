#include<stdio.h>

void isPerfect(){
    int num;
    printf("\nEnter Number: ");
    scanf("%d",&num);

    int divSum = 0;
    int divMul = 1;
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            divSum = divSum + i;
            divMul = divMul * i;
        }
    }
    if(divMul == divSum && divSum == num){
        printf("\n%d is perfect number..",num);
    }
    else{
        printf("\n%d is not a perfect number..",num);
    }
}
void main(){
    isPerfect();
}