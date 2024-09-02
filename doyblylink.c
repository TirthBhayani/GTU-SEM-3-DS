#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *head = NULL;
struct node *new, *temp, *ptr;
void insertbegin(int val)
{
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if (head == NULL)
    {
        head = new;
        new->pre = NULL;
        new->next = NULL;
    }
    else
    {
        new->next = head;
        head->pre = new;
        head = new;
        new->pre = NULL;
    }
}
void insertend(int val)
{
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if (head == NULL)
    {
        head = new;
        new->pre = NULL;
        new->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->pre = temp;
        new->next = NULL;
    }
}
void deletelast()
{
    if (head == NULL)
    {
        printf("empty");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            ;
        {
            temp = temp->next;
        }
        temp->pre->next = NULL;
        free(temp);
    }
}
void deletespecific()
{
    int pos;
    printf("enter position : ");
    scanf("%d", &pos);
    if (pos == 2)
    {
        temp = head;
        head = temp->next;
        head->pre = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        while (pos > 2)
        {
            ptr = temp;
            temp = temp->next;
            pos = pos - 1;
        }
        ptr->next = temp->next;
        temp->next->pre = ptr;
        free(temp);
    }
}
void display()
{
    if (head == NULL)
    {
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int val, pos, choice;
    printf("1.insert a node at the front\n");
    printf("2.insert a node at the end\n");
    printf("3.delete a last node\n");
    printf("4.delete a node before specific position");

    while (1)
    {
        printf("enter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value:");
            scanf("%d", &val);
            insertbegin(val);
            display();
            break;

        case 2:
            printf("enter value ");
            scanf("%d", &val);
            insertend(val);
            display();
            break;

        case 3:
            deletelast();
            display();
            break;

        case 4:
            printf("enter position :\n");
            scanf("%d", &pos);
            printf("enter val");
            scanf("%d", &val);
            deletespecific();
            display();
            break;
        }
    }
}