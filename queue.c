#include <stdio.h>
int f;
int r;
int size;
int isFull()
{
 if (r >= size)
 {
     return 1;
 }
 else
 {
     return 0;
 }
}
int isEmpty()
{
 if (f == -1 || f > r)
 {
 return 1;
 }
 else
 {
 return 0;
 }
}
void enqueue(int a[])
{
 int x;
 printf("ENTER NUMBER TO INSERT : \n");
 scanf("%d", &x);
        if (isFull() == 1)
        {
         printf("QUEUE OVERFLOW : ");
        return;
        }
         else if (r == -1)
             {
             f = 0;
             r = 0;
             }
             else
             {
            r++;
            }
            a[r] = x;
            }
void dequeue(int a[])
{
    if (isEmpty() == 1)
    {
    printf("QUEUE UNDERFLOW : ");
    return;
    }
    else if (f > r)
    {
         f = -1;
         r = -1;
     }
     else
    {
    f++;
    printf("deleted element %d\n",a[f-1]);
     }
}
void display(int a[])
{
 for (int i = f; i <= r; i++)
 {
     printf("%d\n", a[i]);
 }
}
void peek(int a[])
{
    printf("%d\n", a[f]);
}
void main()
{
 f = -1;
 r = -1;
 int num;
  int qq = 0;
    printf("ENTER SIZE OF QUEUE : ");
     scanf("%d", &size);
     int a[size + 1];
 do
 {
    printf("ENTER 1.INSERT, 2.DELETE, 3.DISPLAY, 4.PEEK : ");
    scanf("%d", &num);
    switch (num)
 {
         case 1:
         enqueue(a);
         break;
         case 2:
         dequeue(a);
         break;
         case 3:
        display(a);
         break;
         case 4:
         peek(a);
         break;
        default:
        qq = 1;
 }
 } while (qq != 1);
  printf("\n—THE END—\n");
}