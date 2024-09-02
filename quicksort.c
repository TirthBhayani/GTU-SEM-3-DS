#include<stdio.h>
int mid;
void swap(int *i,int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
    void quicksort(int a[],int *pivot){
        for(int i=0;i<5;i++)
        {
            if(a[i]< pivot){
                swap(&a[i],&a[i+1]);
            }
        }
        for(int i=0;i<5;i++)
        {
            if(a[i]>pivot){
                mid = i;
                swap(&a[i],&pivot);
            }
        }
        sort(a,mid);
    }
    void sort(int a[],int mid){
        for(int i=0;i<mid;i++){
            if(a[i]>a[i+1]){
                swap(&a[i],&a[i+1]);
            }
        }
        for(int i=mid;i<5;i++){
            if(a[mid+1]>a[mid+2]){
                swap(&a[mid+1],&a[mid+2]);
            }
        }
    }
void main()
{
   int a[]={11,2,34,1,30};
   int *pivot = 30;
   quicksort(a,pivot);
   
   for(int i=0;i<5;i++)
   {
    printf("%d ",a[i]);
   }
}
