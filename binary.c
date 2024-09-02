#include<stdio.h>
#include<time.h>
void binarysearch(int ar[],int key,int si,int ei){
    int mid = si + (ei-si)/2;
    if( ar[mid] == key ){
        printf(" array index %d",mid);
    }
    else if(key>ar[mid]){
        binarysearch(ar,key,mid+1,ei);
    }
    else if(key<ar[mid]){
        binarysearch(ar,key,si,mid-1);
    }
    return;
}
void main(){
     time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
    int ar[] = {1,2,3,4,5};
    int key = 4;
    binarysearch(ar,key,0,4);
}