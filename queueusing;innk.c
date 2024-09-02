#include<stdio.h>
#include<stdlib.h>
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};
int dequeue()
{
    int val = -1;

    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty..!!");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
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
    struct node *ptr;
    while (ptr != NULL)
    {
        printf("Queue element is: %d\n", ptr->data);

        ptr = ptr->next;
    }
}
int main()
{
    int val,choice;
    printf("1. INSERT 2.DELETE 3.PEEK 4.DISPLAY\n");
    while(1){
        printf("enter choice\n:");
        scanf("%d",&choice);
        switch(choice){
            case 1 :    printf("enter value : ");
                        scanf("%d",&val);
                        enqueue(val);
                        display();

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

    

