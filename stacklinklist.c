#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 struct node *top = NULL;

struct node
{
    int data;
    struct node *next;
};
void push(int x)
{
    if (isfull(top))
    {
        printf("stack overflow\n");
    }
    else
    {

        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int pop()
{
    if (isempty(top))
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("POPED ELEMENT %d ->\n",top->data);
       
        top = (top)->next;
      
      // return x;
    }
}
void peep()
{
    printf("%d -> \n",top->data);
}

int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void CHANGE(){
    int y,x;
    printf("enter value you want to change ");
    scanf("%d",&y);
    printf("enter new value :");
    scanf("%d",&x);
    struct node*ptr = top;
    while(ptr->data != y){
        ptr = ptr->next;
    }
    ptr->data = x;
}
int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);

        ptr = ptr->next;
    }
}
int main()
{
     time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
    printf("1.PUSH  2.POP   3.PEEP  4.CHANGE\n");
    int x,choice;
    while(1){
    printf("\nenter choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1 :    printf("enter value :");
                scanf("%d",&x);
                push(x);
                display();
                 break;
        
    case 2 :    pop(x);
                break;
    
    case 3 :    peep();
                break;

    case 4 :    CHANGE();
                display();
                break;
    }

    }
  
}