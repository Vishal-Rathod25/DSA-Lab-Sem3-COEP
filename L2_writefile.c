#include<stdio.h>

void writeFileData(){
    FILE *file;
    file = fopen("datafiles\\out.txt", "w");
    
    fprintf(file,"this will be written to file called out.txt");
    printf("\nFile written successfully");
    fclose(file);
}

void main(){
    writeFileData();
}