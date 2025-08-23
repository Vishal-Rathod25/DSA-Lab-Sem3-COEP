#include<stdio.h>

void copyFile(){
    FILE *fileread = fopen("datafiles\\source.txt", "r");
    FILE *filewrite = fopen("datafiles\\dest.txt", "w");

    if(fileread != NULL){
        char ch;
        while((ch = fgetc(fileread)) != EOF){
            fputc((char)ch,filewrite);
        }
    }
    else{
        printf("\nFile Not Found...");
    }
    printf("\nFile is copied successfully...");
    fclose(fileread);
    fclose(filewrite);
}

void main(){
    copyFile();
}