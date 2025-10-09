#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&newNode->data);\
    newNode->next = NULL;
    return newNode;
}


 void insertBegin(){
    struct node *newNode = createNode();\

    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    printf("\nNode Inserted at begin...");
 }

void insertEnd(){
    struct node *newNode = createNode();

    if(head == NULL){
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nNode inserted at end..");
}

void insertSpecific(){
    struct node *newNode = createNode();
    int key;
    printf("\nEnter key to insert after: ");
    scanf("%d",&key);

    if(head == NULL){
        printf("\nList is empty..");
        free(newNode);
    }
    else{
        struct node *temp = head;

        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("\nKey node not found");
            free(newNode);
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
            printf("\nNode is inserted...");
        }
    }
}

void deleteFirst(){
    if(head == NULL){
        printf("\nList is empty..");
    }
    else{
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteLast(){
    if(head == NULL){
        printf("\nList is empty..");
    }
    else{
        struct node *temp = head;
        struct node *prev = head;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void deleteSpecific(){
    if(head == NULL){
        printf("\nList is empty...");
    }
    else{
        printf("\nEnter key data to delete: ");
        int key;
        scanf("%d",&key);
        struct node* temp = head;
        struct node* prev = head;
        while(temp != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            printf("\nKey data not found");
        }
        else{
            prev->next = temp->next;
            free(temp);
            printf("\nNode deleted..");
        }
    }
}

void displayList(){
    if(head == NULL){
        printf("\nList is empty...");
    }
    else{
        struct node *temp = head;
        do{
            printf("%d\t",temp->data);
            temp = temp->next;
        }while(temp != NULL);
    }
}

void count(){
    int count = 0;
    if(head == NULL){
        count = 0;
    }
    else{
        struct node *temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
    }
    printf("\nThe count of elements is: %d",count);
}

void search(){
    printf("\nEnter data to search: ");
    int key;
    scanf("%d",&key);

    struct node* temp = head;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }

        if(temp == NULL){
            printf("\nData not found");
        }
        else{
            printf("\nData found..");
        }
}

void main(){

    printf("\nHello VIshal ");
    int choice;

    while(1){
        printf("\n1 - Insert Begin");
        printf("\n2 - Insert End");
        printf("\n3 - Insert Specific Position");
        printf("\n4 - Delete first");
        printf("\n5 - Delete last");
        printf("\n6 - Delete specific");
        printf("\n7 - Display");
        printf("\n8 - Count");
        printf("\n9 - Search element");
        printf("\n10 - Exit");
    
        printf("\n\nEnter Operation Choice: ");
    scanf("%d",&choice);
        switch(choice){
            case 1: 
                insertBegin();
                break;
            case 2: 
                insertEnd();
                break;
            case 3: 
                insertSpecific();
                break;

            case 4: 
                deleteFirst();
                break;
            case 5: 
                deleteLast();
                break;
            case 6: 
                deleteSpecific();
                break;
            case 7: 
                displayList();
                break;
            case 8:
                count();
                break;
            case 9:
                search();
                break;
            case 10:
                exit(0);
                break;        
        }
    }
}