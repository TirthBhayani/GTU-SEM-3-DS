
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* l;
    struct node* r;
};

struct node* nodecreate(int data)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->l = NULL;
    new->r = NULL;
    return new;
}
int main()
{
    struct node *rooot = nodecreate(1);
    struct node *node1 = nodecreate(2);
    struct node *node2 = nodecreate(3);
    struct node *node3 = nodecreate(4);
    struct node *node4 = nodecreate(5);
    struct node *node5 = nodecreate(6);
    struct node *node6 = nodecreate(7);

    rooot->l=node1;
    rooot->r=node2;

    node1->l = node3;
    node1->r = node4;

    node2->l = node5;
    node2->r = node6;

    printf("   %d  \n",rooot->data);
     printf("  /  |  \n");
    printf("%d    %d\n",node1->data,node2->data);
 printf("/  |    /  | \n");
    printf("%d  %d  %d  %d \n",node3->data,node4->data,node5->data,node6->data);

}