#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* right;
    int data;
    struct node* left;
};
typedef struct node node;

node* insertAtBegDouble(node* start,int data);
node* insertAtLastDouble(node* start,int data);
node* insertBeforeElementDouble(node* start,int data,int element);

node* deleteAtBegDouble(node* start);
node* deleteAtLastDouble(node* start);
node* deleteElementDouble(node* start,int element);


int searchDouble(node* start, int element);
void traverseDoubleForward(node* start);
void traverseDoubleBackward(node* start);

node* sortDouble(node* start);
void merge(node* start1,node* start2);

int main(){

    node* start = NULL;
    start = insertAtBegDouble(start,10);
    start = insertAtLastDouble(start,20);
    start = insertAtLastDouble(start,30);
    start  = insertAtLastDouble(start,40);
    traverseDoubleForward(start);
    traverseDoubleBackward(start);
    start = insertBeforeElementDouble(start,100,20); // start,data,element
    traverseDoubleForward(start);

    //sortDouble(start);
    traverseDoubleForward(start);

    start = deleteAtBegDouble(start);
    start = deleteAtBegDouble(start);
    start = deleteAtBegDouble(start);
    
    traverseDoubleForward(start);
    sortDouble(start);
    traverseDoubleForward(start);
    return 0 ;
}

node* insertAtBegDouble(node* start,int data){
    node* current;
    if(start == NULL){
        printf(" Linked List Is Empty !!!\n Creating One !\n");
        current = (node*)malloc(sizeof(node));
        current->left = NULL;
        current->right = NULL;
        current->data = data;
        return current;
    }else{
        current = (node*)malloc(sizeof(node));
        current->left = NULL;
        current->right = start;
        current->data = data;
        start->left = current;
        return current;
    }
}

node* insertAtLastDouble(node* start,int data){
    node* current;
    if(start == NULL){
        printf(" Linked List Is Empty !!!\n Creating One !");
        current = (node*)malloc(sizeof(node));
        current->left = NULL;
        current->right = NULL;
        current->data = data;
        return current;
    }else if(start->right == NULL){
        current = (node*)malloc(sizeof(node));
        current->left = start;
        current->right = NULL;
        current->data = data;
        start->right = current;
        return start;
    }else{
        while(current->right != NULL){
            current = current->right;
        }
        current->right = (node*)malloc(sizeof(node));
        current->right->left = current;
        current = current->right;
        current->data = data;
        current->right = NULL;
        return start;
    }
}
node* insertBeforeElementDouble(node* start,int data,int element){
    node* current;
    node* preCurrent;
    if(start == NULL){
        return NULL;
    }
    if(start->data == element){
        start = insertAtBegDouble(start,data);
    }else{
        current = start;
        while(current->data != element){
            current = current->right;
            if(current == NULL){
                printf("Element Not Found !!");
                return start;
            }
        }
        preCurrent = current->left;
        preCurrent->right = (node*)malloc(sizeof(node));
        preCurrent->right->left = preCurrent;
        preCurrent = preCurrent->right;
        preCurrent->data = data;
        preCurrent->right = current;
        current->left = preCurrent;
        return start;
    }
}

node* deleteAtBegDouble(node* start){
    if(start == NULL){
        return NULL;
    }else if(start->right == NULL){
        free(start);
        return NULL;
    }else{
        start = start->right;
        free(start->left);
        start->left = NULL;
        return start;
    }
}

node* deleteAtLastDouble(node* start){
    node* current = start;
    if(start == NULL){
        return NULL;
    }else if(start->right == NULL){
        free(start);
        return NULL;
    }else{
        while(current->right != NULL){
            current = current->right;
        }
        current->left->right = NULL;
        free(current);
        return start;
    }
}

node* deleteElementDouble(node* start,int element){
    node* current = start;
    if(start == NULL){
        return NULL;
    }else if((start->data == element) && (start->right == NULL)){
        free(start);
        return NULL;
    }else if((start->right->data == element) && (start->right->right == NULL)){
        current = current->right;
        free(current);
        start->right = NULL;
        return start;
    
    }else{
        while(current->data != element){
            current = current->right;
        }
        if(current->right == NULL){
            current->left->right = NULL;
            free(current);
            return start;
        }
        current->left->right = current->right;
        current->right->left = current->left;
        current->left = NULL;
        current->right = NULL;
        free(current);
        return start;
    }
}


int searchDouble(node* start, int element){
    int index = 0;
    node* current = start;
    if(start == NULL){
        return -1;
    }else if(start->data == element){
        return 0;
    }else{
        while(current->data != element){
            current = current->right;
            if(current == NULL){
                return -1;
            }
            index = index + 1;
        }
        return index;
    } 
}

void sortDouble(node* start){
     node* current = start;
     node* PreCurrent = start;
     if(start == NULL){
         printf("Empty Linked List !!\n");
     }else{
         if(start->right == NULL){
             printf("Linked List Contains Only One Node !!!\n");
         }else {
             while(current->right != NULL){
                 PreCurrent = current->right; 
                 while(PreCurrent != NULL){
                     if(current->data > PreCurrent->data){
                         int temp = current->data;
                         current->data = PreCurrent->data;
                         PreCurrent->data = temp;
                     }
                     PreCurrent = PreCurrent->right;
                 }
                 current = current->right;
             }   
         }
     }
}

node* merge(node* start1,node* start2){
    node* current;
    if(start1 == NULL || start2 == NULL){
        printf("Error Either one is empty !!");
    }else{
        current = start1;
        while(current->right != NULL){
            current = current->right;
        }
        current->right = start2;
        start2->left = current;
        sortDouble(start1);
        return start1;
    }
}

void traverseDoubleForward(node* start){
    node* current = start;
    if(current == NULL){
        printf(" Linked List Empty !!! \n");
    }else{
        while(current != NULL){
            printf("%d ",current->data);
            current = current->right; 
       }
       printf("\n");
    }
}

void traverseDoubleBackward(node* start){
    node* current = start;
    if(current == NULL){
        printf(" Linked List Empty !!! \n");
    }else{
        while(current->right != NULL){
            current = current->right; 
       }
       while(current != NULL){
          printf("%d ",current->data);
           current = current->left;
       }
       printf("\n");
    }
}
