#include<stdio.h>
#include<time.h>
int main()
{   
     time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
    int x;
    printf("enter size of array:");
    scanf("%d",&x);
    int a[x];
    for(int t=0;t<x;t++){
        scanf("%d",&a[t]);
    }
    int temp;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
        if(a[j]>a[j+1])
        {
            temp=a[j+1];
            a[j+1]=a[j];
            a[j]=temp;
        }
        }
    } 
    for(int i=0;i<x;i++){
        printf( "%d ",a[i]);
    }

}
