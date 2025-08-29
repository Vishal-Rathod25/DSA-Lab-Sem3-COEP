#include<stdio.h>
#include<math.h>

void fillData(){
    FILE *file = fopen("datafiles\\signdata.txt","w");

    if(file == NULL){
        printf("\nFile is not opened");
    }
    else{
        for(int i = 0; i < 100; i++){
            fprintf(file,"%d %f\n",i,sin(i*0.1));
        }
        printf("\nFile is written");
    }
}

void main(){
    fillData();
}