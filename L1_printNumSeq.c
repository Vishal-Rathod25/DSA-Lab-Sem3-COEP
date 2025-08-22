#include<stdio.h>

void printSequence(){
    int size;
    printf("\nEnter the length of array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < 3; i++){
        if(i == 0){
            for(int j = 0; j < size; j++){
                if(arr[j] < 0)
                    printf("%d\t",arr[j]);
            }
        }
        else if(i == 1){
            for(int j = 0; j < size; j++){
                if(arr[j] == 0)
                    printf("%d\t",arr[j]);
            }
        }
        else if(i == 2){
            for(int j = 0; j < size; j++){
                if(arr[j] > 0)
                    printf("%d\t",arr[j]);
            }
        }
    }
}
void main(){
    printSequence();
}