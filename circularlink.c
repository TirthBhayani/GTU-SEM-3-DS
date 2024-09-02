#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;
struct node *temp;

void insertAtend(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if (first == NULL)
    {
        first = new;
        new->next = first;
    }
    else
    {
        temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = first;
    }
}

void insertbefore(int val, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if (pos == 1)
    {
        newnode->next=first;
        struct node *p;
        p=first;
        while(p->next!=first){
            p=p->next;
        }
        first = newnode;
        p->next=first;
    }
    else
    {
        struct node *hi=first;
        for(int i=1;i<pos-1;i++){
            hi=hi->next;
        }
        newnode->next=hi->next;
        hi->next=newnode;
    }
}
void deletefirst()
{
    if (first == NULL)
    {
        printf("empty");
    }
    else if (first->next == first)
    {
        printf("There i only one node : %d",first->data);
        free(first);
    }
    else
    {
        struct node *temp1,*te;
        temp1 = first;
        first=temp1->next;
        te=first;
        while (te->next!=temp1)
        {
            te=te->next;
        }
        te->next=first;
        free(temp1);
    }
}
void deleteafter(int pos)
{
    if (pos == 1){
        deletefirst();
        return;
    }
        struct node *tem = first;
        struct node *k;
        for(int i=1;i<pos;i++){
            tem=tem->next;
        }
        k=tem->next;
        tem->next=tem->next->next;
        free(k);
}
void display()
{
    if(first!=NULL){
        struct node *ptr = first;
        if(ptr->next==first){
            printf("%d\n",ptr->data);
        }
        else{
        while (ptr->next != first)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n",ptr->data);
        }
    }
}

void main()
{
    int pos, val, choice;
    printf("1.insert a node at the end\n");
    printf("2.insert a node before specific position\n");
    printf("3.delete a first node\n");
    printf("4.delete a node after specific position\n");
    printf("0.end the program.\n");
    while (1)
    {
        printf("enter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value :\n");
            scanf("%d", &val);
            insertAtend(val);
            display();
            break;

        case 2:
            printf("enetr position :\n");
            scanf("%d", &pos);
            printf("enter value\n");
            scanf("%d", &val);
            insertbefore(val, pos);
            display();
            break;

        case 3:
            deletefirst();
            display();
            break;

        case 4:
            printf("enter position :\n");
            scanf("%d", &pos);
            deleteafter( pos);
            display();
            break;
        case 0:
            exit(0);
        default:
            printf("Wrong choice!!\n");
        }
    }
}