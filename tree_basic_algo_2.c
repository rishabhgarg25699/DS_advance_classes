#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;

node* create(node* root);
int traverse(node* root);

int main(){
    node* root = NULL;
    create(root);
    traverse(root);




    return 0;
}

node* create(node* root){
    if(root == NULL){
        int temp;
        root = (node*)malloc(sizeof(node));
        printf("Enter the value of root node :- ");
        scanf("%d",&temp);
        root->data = temp;
    }
    int temp_left;
    int temp_right;
    printf("Enter the value of Right part of %d :- ",root->data);
    scanf("%d",&temp_right);
    printf("Enter the value of Left part of %d :- ",root->data);
    scanf("%d",&temp_left);
    if(temp_left == -1 && temp_right == -1){
        root->left == NULL;
        root->right == NULL;
        return root;
    }else if(temp_left == -1 && temp_right != -1){
        root->right = (node*)malloc(sizeof(node));
        root->right->data = temp_right;
        create(root->right);   
    }else if(temp_left != -1 && temp_right == -1){
      root->left = (node*)malloc(sizeof(node));
      root->left->data = temp_left;
      create(root->right);   
    }else if(temp_left != -1 && temp_right != -1){
        root->left = (node*)malloc(sizeof(node));
        root->right = (node*)malloc(sizeof(node));
        root->left->data = temp_left;
        root->right->data = temp_right;
        create(root->right);
        create(root->left);
    }
    return root;
}

int traverse(node* root){
    if(root == NULL){
        return 0;
    }else if(root->left == NULL && root->right == NULL){
        printf("%d ",root->data);
        return 0;
    }else{
        traverse(root->left);
        printf("%d ",root->data);
        traverse(root->right);
        return 0;
    }
}
