// A simple program to demonstrate the tower of hanoi.
// Move N-1 disk from source to auxialry then move last disk to destination then move N-1 disk to auxilary to destination.

#include<stdio.h>
#include<stdlib.h>

int toh(int N,char source,char destination, char auxilary);
int main(){
    char a = 'A',b = 'B',c = 'C';
    int N = 64;
    toh(N,a,b,c);

    return 0;
}

int toh(int N,char source,char destination, char auxilary){
    if(N == 1){
        printf("Move disk %d from %c to %c . \n",N,source,destination);
        return 0;
    }else{
        toh((N-1),source,auxilary,destination);
        printf("Move disk %d from %c to %c .\n",N,source,destination);
        toh((N-1),auxilary,destination,source);
    }
}
