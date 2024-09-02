#include<stdio.h>

void binarysort(int ar[],int key,int si,int ei){
    int mid = si + (ei-si)/2;

    if( ar[mid] == key ){
        printf("%d",mid);
    }
    else if(key>ar[mid]){
        binarysort(ar,key,mid+1,ei);
    }
    else if(key<ar[mid]){
        binarysort(ar,key,si,mid-1);
    }
}


void main(){
    int ar[] = {3,6,7,8,9,10};
    int key = 8;
    binarysort(ar,key,0,5);
}