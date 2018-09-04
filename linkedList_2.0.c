#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
struct node{
    int data;
    struct node* next;
};
typedef struct node node;

node* insertAtBeg(node* start,int data);
node* insertAtLast(node* start,int data);
node* insertAtRandomIndex(node* start,int index,int data); // (start,index,data)
node* insertBefore(node* start,int data,int before);

node* deleteAtBeg(node* start);
node* deleteAtLast(node* start);
node* deleteAtRandomIndex(node* start,int index);
node* deleteItem(node* start,int data);

node* sort(node* start);
node* merge(node* start1,node* start2);

int searchItem(node* start, int data);
void traverse(node* start);

int main(){
    node* start = NULL;
    node* start2;
    printf("My Sample LinkedList :-            ");
    start = insertAtBeg(start,10);
    for(int i = 2; i <=10; i++){
        start = insertAtLast(start,(10*i)); // My sample linkedList
    }
    traverse(start); // Printing sample linkedlist
    printf("\n");

    printf("Inserting Zero At Begining :-      ");
    start = insertAtBeg(start,00);  
    traverse(start);
    
    printf("Inserting 500 at 5th index :-      ");
    start = insertAtRandomIndex(start,5,500); 
    traverse(start);
    
    printf("Inserting 400 before 500 :-        ");
    start = insertBefore(start,400,500); 
    traverse(start);

    printf("Inserting 1000 at last:-           ");
    start = insertAtLast(start,1000);
    traverse(start);
    printf("\n");
    
    printf("Deleting at begining :-           ");
    start = deleteAtBeg(start);
    traverse(start);
    
    printf("Deleting at last :-               ");
    start = deleteAtLast(start);
    traverse(start);
    
    printf("Deleting at given index 6 :-      ");
    start = deleteAtRandomIndex(start,6);
    traverse(start);
    
    printf("Deleting a given element 70 :-    ");
    start = deleteItem(start,70);
    traverse(start);
    
    printf("Sorted Linkedlist :-              ");
    start = sort(start);
    traverse(start);
    
    // printf("Same Linkedlist Merged :-         ");
    // start2 = start;
    // start = merge(start,start2);
    // traverse(start);
    return 0;
}

node* insertAtBeg(node* start,int data){
    node* current;
    if (start == NULL){
        start = (node*)malloc(sizeof(node));
        start->data = data;
        start ->next = NULL;
        return start;
    }else{
        current = (node*)malloc(sizeof(node));
        current ->data = data;
        current ->next = start;
        start = current;
        return start;
    }
}

node* insertAtLast(node* start,int data){
    node* current;
    if(start == NULL){
        start = (node*)malloc(sizeof(node));
        start->data = data;
        start ->next = NULL;
        return start;
    }else{
        current = start;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (node*)malloc(sizeof(node));
        current = current->next;
        current->data = data;
        current->next = NULL;
        return start;
    }
}

node* insertAtRandomIndex(node* start,int index,int data){
    node* current;
    int count = 0;
    if(start == NULL){
        return NULL;
    }
    current = start;
    while(current != NULL){
        count = count + 1;
        current = current -> next;
    }
    // printf("%d\n",count);
    // Current has NULL
    if(index == 0){
        start = insertAtBeg(start,data);
    }else if(index == count){
        start = insertAtLast(start,data);
    }else if (index < count){
        current = start;
        node* preCurrent = start;
        for(int i = 1; i < index; i++){
            current = current ->next;
        }
        for(int i = 1; i < (index-1); i++){
            preCurrent = preCurrent ->next;
        }
        preCurrent->next = (node*)malloc(sizeof(node));
        preCurrent = preCurrent->next;
        preCurrent->data = data;
        preCurrent->next = current;
    }
    return start;
}

node* insertBefore(node* start,int data,int before){
    node* current;
    node* preCurrent;
    int boolean = 0;
    
    current = start;
    while(current != NULL){ // Searching Part
        if(current->data == before){
            boolean = 1;
            break;
        }            
        current = current ->next;
    }
    if(boolean == 0){
        printf("Item Not Found !!!\n");
        return start;
    }
    if(start == NULL){
        return NULL;
    }else if(start->data == before){
        start = insertAtBeg(start,data);
    }
    else{
        current = start;
        while(current->data != before){
            preCurrent = current;
            current = current->next;
        }
        preCurrent ->next = (node*)malloc(sizeof(node));
        preCurrent = preCurrent->next;
        preCurrent ->data = data;
        preCurrent ->next = current;
    }
    return start;
}

node* deleteAtBeg(node* start){
    node* current;
    if (start == NULL){
        return NULL;
    }else{
        if(start->next == NULL){
            free(start);
            return NULL;
        }else{
            current = start->next;
            free(start);
            return current;
        }
    }
}

node* deleteAtLast(node* start){
    node* current = start;
    node* temp;
    if(start == NULL){
        return NULL;
    }else if(start->next == NULL){
        free(start);
        return NULL;
    }else{
        while(current->next->next != NULL){ // Stop at second last element
            current = current->next;
        }
        temp = current->next;
        free(temp);
        current ->next = NULL;
        return start;
    }
}

node* deleteItem(node* start,int data){
    node* current = start;
    node* percurrent;
    if(start == NULL){
        return NULL;
    } else if(start->data == data){
        current = start;
        start = start->next;
        free(current);
        return start;
    }
    else{
        while(current->data != data){
            percurrent = current;
            current = current->next;
        }
        percurrent->next = current->next;
        free(current);
        return start;    
    }
}

node* deleteAtRandomIndex(node* start,int index){
    node* current;
    node* precurrent;
    int count =0 ;
    if(start == NULL){
        return NULL;
    }
    current = start; 
    while(current != NULL){ // Counting number of elements in linkedlist
        count = count + 1;
        current = current -> next;
    }// Current = NULL
    if(index > count){ 
        printf("Index Out of Range !!! ");
        return start;
    }else if(index == 0){
        start = deleteAtBeg(start);
        return start;
    }else if(index == count){
        start = deleteAtLast(start);
        return start;
    }else{
        current = start;
        precurrent = start;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        for(int i = 0; i < (index-1); i++){
            precurrent = precurrent->next;
        }
        precurrent->next = current->next;
        free(current);
        return start;
    }
}

node* sort(node* start){
    node* current;
    node* afterCurrent;
    if(start == NULL){
        return NULL;
    }
    else if(start->next == NULL){
        return start;
    }else{
        current = start;
        while(current ->next != NULL){
            afterCurrent = current->next;
            while(afterCurrent != NULL){
                if((current->data) > (afterCurrent->data)){
                    int temp = current->data;
                    current->data = afterCurrent->data;
                    afterCurrent->data = temp;
                }
                afterCurrent = afterCurrent->next;
            }
            current = current->next;
        }

    }     
    return start;
}

node* merge(node* start,node* start2){
    node* current = start;
    node* start3;
    if((start == NULL) || (start2 == NULL)){
        printf("Error Either One Is Empty !!!!");
    }else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = start2;
        start3 = sort(start);
        return start3;
    }
}


int searchItem(node* start, int data){
    node* current = start;
    int boolean = 0;
    while(current != NULL){ 
        if(current->data == data){
            boolean = 1;
            break;
        }            
        current = current ->next;
    }
    //printf("Mil Gya !!");
    return boolean;
}

void traverse(struct node *start){
    struct node *current;
    if(start ==NULL){
        printf("LINKED LIST IS EMPTY !!!\n");
    }
    else{
        current = start;
        while(current != NULL){
            printf("%d ",current->data);
            current = current->next;
        }
        printf("\n");
    }
}
