#include<stdio.h>
void div(int a[],int si,int ei){
    int mid;    
    if(si<ei){
    mid = si + (ei-si)/2;
    div(a,si,mid);
    div(a,mid+1,ei);
    merge(a,si,mid,ei);
    }
}
void merge(int a[],int si,int mid,int ei){
    int m[ei-si+1];
    int i1 = si;
    int i2 = mid+1;
    int x = 0;
    while(i1<=mid && i2<=ei){
        if(a[i1]<=a[i2]){
            m[x++]=a[i1++];
        }
        else{
            m[x++]=a[i2++];
        }
    } 
    while(i1<=mid){
        m[x++]=a[i1++];
    }
    while(i2<=ei){
         m[x++]=a[i2++];
    }
    for(int k=si;k<=ei;k++){
            a[k]=m[k];
    }
}
void printele(int a[],int n){
    for(int t=0;t<5;t++){
        printf("%d ",a[t]);
    }
}

int main()
{
    int a[] = {5,67,2,45,6,77};
    int n = 6;
    div(a,0,n-1);
    printele(a,n-1);
}