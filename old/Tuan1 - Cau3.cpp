#include<stdio.h>
int counteven(int* arr, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        scanf("%d",&*(arr+i));
        if(*(arr+i)% 2 == 0) { count++; }
    }
    return count;
}
