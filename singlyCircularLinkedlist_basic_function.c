#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;

node* insertAtLast(node* start,int data);
node* insertAtBeg(node* start,int data);
node* insertBefore(node* start,int data,int element);

node* deleteAtBeg(node* start);
node* deleteAtlast(node* start);
node* deleteElement(node* start,int element);

node* sort(node* start);
node* merge(node* start1,node* start2);

int search(node*start,int element);
void traverse(node* start);

int main(){
    node* start = NULL;
    start = insertAtLast(start,20);
    start = insertAtLast(start,30);
    start = insertAtLast(start,40);
    start = insertAtBeg(start,0);
    start = deleteElement(start,30);
    traverse(start);
    return 0;
}

node* insertAtBeg(node* start,int data){
    node* current = start;
    if(start == NULL){
        current = (node*)malloc(sizeof(node));
        current->data = data;
        current->next = current;
        return current;
    }else if(start->next == start){
        current = (node*)malloc(sizeof(node));
        current->data = data;
        current->next = start;
        start->next = current;
        return current;
    }else{
        node* preCurrent = start;
        do{
            preCurrent = preCurrent->next;
        }while(preCurrent->next != start);
        current = (node*)malloc(sizeof(node));
        current->data = data;
        current->next = start;
        preCurrent->next = current;
        return current;
    }
}
node* insertAtLast(node* start,int data){
    node* current = start;
    if(start == NULL){
        current = (node*)malloc(sizeof(node));
        current->data = data;
        current->next = current;
        return current;
    }else if(start->next == start){
        start->next = (node*)malloc(sizeof(node));
        current = start->next;
        current->next = start;
        current->data = data;
        return start;
    }else{
        current = start;
        do{
            current = current->next;
        }while(current->next != start);
        current->next = (node*)malloc(sizeof(node));
        current = current->next;
        current->data = data;
        current->next = start;
        return start; 
    }
}

node* insertBefore(node* start,int data,int element){
    node* current = start;
    node* preCurrent = start;
    if(start->data == element){
        start = insertAtLast(start,data);
        return start;
    }
    else if (start->next->data == element)
    {
        current = (node*)malloc(sizeof(node));
        current->data = data;
        current->next = start->next;
        start->next = current;
        current = current->next;
        current->next = start;
        return start;
    }else{
        current = start->next;
        do{
            preCurrent = preCurrent->next;
            current = current ->next; 
            if(current->data == element){
                preCurrent->next = (node*)malloc(sizeof(node));
                preCurrent = preCurrent->next;
                preCurrent->data = data;
                preCurrent->next = current;
                break;
            }
        }while(current != start);
        return start;
    }
    
}

node* deleteAtBeg(node* start){
    node* current = start;
    if(start == NULL){
        printf("Linked List is empty !!");
        return NULL;
    }
    do{
        current = current->next;
    }while(current->next != start);
    current->next = start->next;
    current = start;
    start = start->next;
    free(current);
    return start;
}
node* deleteAtlast(node* start){
    node* current = start;
    if(start == NULL){
        printf("List Is Empty !!");
        return NULL;
    }else{
        do{
            current = current->next;
        }while(current->next->next != start);
        free(current->next);
        current->next = start;
        return start;
    }
}
node* deleteElement(node* start,int element){
    node* current = start;
    if(start == NULL){
        printf("Linked List is empty !!");
    }else if(start->data == element){
        free(start);
        return NULL;
    }else{ 
        do{
            current = current->next;
        }while(current->next->data != element);
        node* percurrent = current->next;
        current->next = percurrent->next;
        free(percurrent);
        return start;
    }
}


node* sort(node* start){
    node* current = start;
    if(start == NULL){
        printf("Empty List !!\n");
        return NULL;
    }else if(start->next == NULL){
        printf("Contains only one element, Already sorted !!\n");
        return start;
    }else{
        node* percurrent;
        do{
            percurrent = current->next;
            do{
                if(current->data > percurrent->data){
                    int temp = current->data;
                    current->data = percurrent->data;
                    percurrent->data = temp;
                }
                percurrent = percurrent->next;
            }while(percurrent != start);
            current = current->next;
        }while(current->next != start);
    }
    return start;
}

node* merge(node* start1,node* start2){
    node* current = start1;
    if(start1 == NULL || start2 == NULL){
        printf("Error Either One is empty !!");
        return NULL;
    }
    do{
        current = current->next;
    }while(current->next != start1);
    current->next = start2;
    do{
        current = current->next;
    }while(current->next != start2);
    current->next = start1;
    start1 = sort(start1);
    return start1;
}


int search(node* start,int element){
    int indexPointer = -1;
    int indicator = -1;
    node* current = start;
    do{
            indexPointer = indexPointer + 1;
            if(current->data == element){
               return indexPointer;
            }
            current = current->next;
    }while(current != start);
    return indicator; // If item is not found then -1 will be returned.
}

void traverse(node* start){
    if(start == NULL){
        printf(" Linked List Empty !!");
    }else if(start->next == NULL){
        printf("%d ",start->data);
    }else{
        node* current = start;
        do{
            printf("%d ",current->data);
            current = current->next;
        }while(current != start);
    }

}
