#include<stdio.h>
#include<stdlib.h>


struct BinaryST{
    struct BinaryST* lchild;
    int data;
    struct BinaryST* rchild;
};

struct BinaryST * tree = NULL;

struct BinaryST* getBinaryST(){
    struct BinaryST *bst = (struct BinaryST*)malloc(sizeof(struct BinaryST));
    bst->lchild = NULL;
    bst->rchild = NULL;
}

void insertNode(struct BinaryST *root, int data){

    if(root == NULL){
        tree = getBinaryST();
        tree->data = data;
    }
    else{
        if(data > root->data){
            if(root->rchild == NULL){
                root->rchild = getBinaryST();
                root->rchild->data = data;
            }
            else{
                insertNode(root->rchild,data);
            }
        }
        else{
            if(root->lchild == NULL){
                root->lchild = getBinaryST();
                root->lchild->data = data;
            }
            else{
                insertNode(root->lchild, data);
            }
        }
    }


}
void inorder(struct BinaryST* root){
    if(root){
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}
void preorder(struct BinaryST* root){
    if(root){
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(struct BinaryST* root){
    if(root){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}

void main(){
    int choice;
    int data;
    while(1){
        printf("\n1 - Insert Node");
        printf("\n2 - In-order Traversal");
        printf("\n3 - Pre-order Traversal");
        printf("\n4 - Post-order Traversal");
        printf("\n5 - Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insertNode(tree,data);
                break;
            case 2: 
                inorder(tree);
                break;
            case 3: 
                preorder(tree);
                break;
            case 4: 
                postorder(tree);
                break;
            case 5: 
                exit(0);
                break;
                 
        }
    }
}