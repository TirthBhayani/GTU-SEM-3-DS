#include <stdio.h>
#include <conio.h>
#define size 5
int f = -1, r = -1;
int a[size];
int flag=0;
void enqueue()
{
    // int x;
    if (isfull())
    {
        printf("queue overflow\n");
    }
    else
    {
        if(flag==0){
            f++;
            flag=1;
        }   
        r = (r + 1) % size;
        printf("enter element:");
        scanf("%d", &a[r]);
        // a[r] = x;
        printf(" %d inserted\n", a[r]);
    }
}
void dequeue()
{
    if (isempty())
    {
        printf("queue underflow\n");
    }
    else
    {
        printf("deleted element %d\n", a[f]);
         a[f]=-1;
        f = (f + 1) % size;
        // printf("<<%d  %d>>",r,f);
    }
}
int isfull()
{
    if ((r + 1) % size == f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (r+1 == f)
    {
        // printf("--%d %d--",r,f);
        return 1;
    }
    else
    {
        // printf("-!-%d %d-!-",r,f);
        return 0;
    }
}
void display()
{
    int i;
    if (isempty())
    {
        printf("empty queue");
    }
    else
    {
        // printf("<------ %d %d ----->",r,f);
        for (i = f; i <= r; i++)
        {
            printf("%d\n", a[i]);
        }
    }
}
void peek()
{
    printf("%d\n",a[f]);
}
void main()
{
    // int t;
    // printf("ENTER SIZE OF QUEUE : ");
    //  scanf("%d", &t);
    int num;
    int qq = 0;
    // int a[size + 1];
    do
    {
        printf("ENTER 1.INSERT, 2.DELETE, 3.DISPLAY, 4.PEEK : ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            qq = 1;
        }
    } while (qq != 1);
    printf("\n—THE END—\n");
}