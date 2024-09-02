#include<stdio.h>
int n;
int sum =0;
int count,count1,count2 =0;

int loop(int n)
{
    for(int i=0;i<n;i++)
    {
        sum = sum + i;
        count++;
    }
   // return sum;
    return count;
}
int recursion(int n)
{
    if(n==1)
    {
        count1++;
        return n;
    }
    count1++;
    return n+recursion(n-1);
}
int equation(int n)
{
    count2++;
    return (n*n+1)/2;
}
int main()
{
    printf("enter n :");
    scanf("%d",&n);

    int lp = loop(n);
    int rc = recursion(n);
    int eq = equation(n);

    printf("loop steps %d : ",count);
    printf("recursion steps %d  : ",count1);
    printf("equation steps %d : ",count2);
    return 0;
}