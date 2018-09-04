#include<stdio.h>
#include<stdlib.h>

int fillUpto(int array[],int size){
    int i = 0;
    while(array[i] != -1){
        i = i + 1;
    }
    return i;
}

int menu(){
    int choice;
        printf("\n\n    ---Basic Operations On An Array---\n\n\n");
    
        printf(" 1. Insert Element At Begining of Array\n");
        printf(" 2. Insert Element At End of Array\n");
        printf(" 3. Insert Element At Random Place In Array\n");
        printf(" 4. Delete Element At Begining of Array\n");
        printf(" 5. Delete Element At End of Array\n");
        printf(" 6. Delete Element At Random Place In Array\n");
        printf(" 7. Print Array\n");
        printf(" 8. Merge Another Array With Existing One \n");
        printf(" 9. Search An Element In Array\n");
        printf(" 10. Sort Array\n");
        printf("\n\n");
        //printf(" 99. Perform Another Operation\n");
        printf(" 100. Exit");
        
        printf("\n\nEnter Your Choice ==> ");
        scanf("%d",&choice);
    
    return choice;
}



int traversing(int data_array[],int size){
    int i = 0;

    for(i = 0; i < fillUpto(data_array,size); i++){
        printf("%d ",data_array[i]);
    }
    printf("\n");
    return 1;
}

int sort(int array[],int size){
    size = fillUpto(array,size);
    int i = 0,j = 0;
    int temp;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i -1; j++){
            if (*(array + j) > *(array+j +1)){
                temp = *(array + j);
                *(array + j) = *(array + j +1);
                *(array+j+1) = temp;
            }
        }
    }

}

int Search(int array[],int size){
    int item,k = 0;
    size = fillUpto(array,size);
    printf("Enter Item You Want to Search :- ");
    scanf("%d",&item);
    for(int i = 0; i < size; i++){
        if (array[i] == item){
            printf("your Item %d In Found At %d Place.\n",item,(i+1));
            k++;
        }
        
    }    
    if (k == 0){
        printf("Your Item Not found !!\n");
    }
}

int isbeg(int data_array[],int size){
    int item,temp = size;
    int i,j;
    
    size = fillUpto(data_array,size);
    if(size == temp){
        printf("OverFlow !! \n");
    }
    else{
        printf("Enter Item You Want To Insert :- ");
        scanf("%d",&item);
        if(*data_array == -1){
            *data_array = item;
        }
        else{
            for(i = size-1; i >= 0; i--){
                *(data_array + i + 1) = *(data_array + i);
            }
            *(data_array + 0) = item;
        }
    }
}


int islast(int data_array[],int size){
    int item,temp = size;
    int i,j;
    
    size = fillUpto(data_array,size);
    if(size == temp){
        printf("OverFlow !! \n");
    }
    else{
        printf("Enter Item You Want To Insert :- ");
        scanf("%d",&item);
        if(*(data_array + (size)) == -1){
            *(data_array + size) = item;
        }
        
    }
}

int israndom(int data_array[],int size){
    int item,temp;
    int pos_rnd_itm;
    int i ,j; 
   
    size = fillUpto(data_array,size);
   
    if(size == temp){
        printf("OverFlow !! \n");
    }
    else{
        printf("Enter Item You Want To Insert :- ");
        scanf("%d",&item);
        for(i = 0; i < size; i++){
            if (data_array[i] > item){
                // i returns with index of element which is greater than item.
                break;
            }     
        }
        if(i == size){
                *(data_array + size) = item;
            }
        else if(i == 0){
                for(i = size-1; i >= 0; i--){
                    *(data_array + i + 1) = *(data_array + i);
                }
                *(data_array + 0) = item;
        }
        else{
                for(j = size-1; j >= i; j--){
                    *(data_array + j + 1) = *(data_array + j);
                }
                *(data_array + i) = item;

           }

    }

}

int dellast(int data_array[],int size){
    size = fillUpto(data_array,size);
    if (size == 0){
        printf("UnderFlow !!!");
    }
    else{
        *(data_array + size - 1) = -1;
    }
}

int delfst(int data_array[],int size){
    int i,j;
    size = fillUpto(data_array,size);
    if(data_array[0] == -1){
        printf("UnderFlow !!!\n");
    }else{
        for(i = 0; i < size; i++){
        *(data_array + i ) = *(data_array + i + 1);
        }
        *(data_array + (size-1)) = -1;
    }
}




int delrandom(int data_array[],int size){
    int item,temp;
    int pos_rnd_itm;
    int i ,j; 
   
    size = fillUpto(data_array,size);
   
    if(size == temp){
        printf("OverFlow !! \n");
    }
    else{
        printf("Enter Item You Want To Delete :- ");
        scanf("%d",&item);
        for(i = 0; i < size; i++){
            if (data_array[i] == item){
                // i returns with index of element which is equal to item.
                break;
            }     
        }
        if(i == size){
                printf("Item Not Found !!!\n");
            }
        else if(i == size -1){
            *(data_array + i) = -1;
        }
        else if(i == 0){
                for(i = 0; i <= size; i++){
                    *(data_array + i) = *(data_array + i + 1);
                }
                *(data_array + (size-1)) = -1;
        }
        else{
                for(j = i; j < size; j++){
                    *(data_array + j ) = *(data_array + j + 1);
                }
                *(data_array + (size-1)) = -1;
           }

    }

}
