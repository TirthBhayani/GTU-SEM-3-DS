#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};
int dequeue()
{
    int val;

    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty..!!");
    }
    else
    {
        printf("delete element -> %d\n",f->data);
        f = f->next;
    }
    
}
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full..!!");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
void display()
{
    struct node *ptr =f;
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void peek()
{
    printf("%d ->",f->data);
}
int main()
{
     time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
    int val,choice;
    printf("1. INSERT 2.DELETE 3.PEEK 4.DISPLAY\n");
    while(1){
        printf("enter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :    printf("enter value : ");
                        scanf("%d",&val);
                        enqueue(val);
                        display();
                        break;

            case 2 :    dequeue();
                        break;

            case 3 :    peek();
                        break;

            case 4 :    display();
                        break;
        }
    }
    // enqueue(1);
    // enqueue(2);
    // enqueue(3);
    // linkedlisttraversal(f);
    // printf("dequeued element :%d\n", dequeue());
    // printf("dequeued element :%d\n", dequeue());
    // printf("dequeued element :%d\n", dequeue());
     

    // return 0;
}

    

