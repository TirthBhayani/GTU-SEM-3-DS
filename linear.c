#include<stdio.h>
#include<time.h>
int main()
{
    time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
    int size,key;
    printf("enter size of array:");
    scanf("%d",&size);
    int a[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter element you want to find:");
    scanf("%d",&key);
    for(int i=0;i<size;i++)
    {
        if(a[i]==key){
            printf("array index: %d",i);
    }
}
}