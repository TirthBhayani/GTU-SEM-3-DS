#include <stdio.h>
#include<time.h>
int a[5] = {65,3,22,45,32};
int b[6];

void merging(int low, int mid, int high) {
   int l1, l2, i;
   l1 = low;
   l2 = mid+1;
   i=0;
   for(i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
    time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
   int i;
   sort(0, 4);
   printf("sorted array:");
   for(i = 0; i <= 5; i++)
      printf("%d ", a[i]);
}