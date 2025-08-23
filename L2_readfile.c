#include<stdio.h>

void readFileData(){
    FILE *file;
    file = fopen("datafiles\\data.txt", "r");

    if(file != NULL){
        char ch;
        while((ch = fgetc(file)) != EOF){
            printf("%c",(char)ch);
        }
    }
    else{
        printf("\nFile Not Found...");
    }
    fclose(file);
}

void main(){
    readFileData();
}