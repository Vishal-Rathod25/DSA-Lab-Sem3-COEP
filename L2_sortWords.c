#include<stdio.h>

void sortWords(){
    FILE *file;
    file = fopen("datafiles\\words.txt","r");
    
    char arr[10][10];
    int ch;
    int p = 0;
    int k = 0;

    //storing the values into the 2D Array
    while((ch = fgetc(file)) != EOF && p < 10){
        if(ch != 32 && ch != '\n'){   // skip spaces/newlines
            arr[p][k] = (char)ch;
            k++;
        }
        else{
            arr[p][k] = '\0';   // terminate string
            p++; 
            k = 0;
        }
    }
    arr[p][k] = '\0'; // terminate last word if file doesn't end with space

    //sorting (based on first character)
    for(int s = 0; s < 10; s++){
        for(int i = 0; i < 10 - 1; i++){
            int j = i + 1;
            if(arr[i][0] > arr[j][0]){
                for(int k = 0; k < 10; k++){
                    char temp = arr[i][k];
                    arr[i][k] = arr[j][k];
                    arr[j][k] = temp;
                }
            }
        }
    }

    //printing the sorted 2D Array
    for(int i = 0; i < 10; i++){
        if(arr[i][0] != '\0'){
            printf("%s\n", arr[i]);
        }
            
    }

    FILE *filew = fopen("datafiles\\sorted.txt","w");
    for(int l = 0; l < 10; l++){
        if(arr[l][0] != '\0'){
            fprintf(filew,arr[l]);
            fprintf(filew," ");
        }
    }
}

void main(){
    sortWords();
}
