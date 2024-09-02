#include<stdio.h>
#include<conio.h>
void toh(int n,int src,int helper,int desct)
{    if(n==1)
    {
        printf("trasfer disk from %c to %c to %c\n",src,helper,desct);
        return;
    }
        toh(n-1,src,desct,helper);
        toh(1,src,helper,desct);
        toh(n-1,helper,src,desct);
}
int main()
{
    toh(3,'a','b','c');
}