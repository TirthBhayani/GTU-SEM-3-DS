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
void preorder(struct node* root){
    if(root!= NULL)
    {
        printf("%d ",root->data);
        preorder(root->l);
        preorder(root->r);
    }
}
void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->data);
    }
}
void inorder(struct node* root){
    if(root != NULL)
    {
        inorder(root->l);
        printf("%d ",root->data);
        inorder(root->r);
    }
}
struct node* insert(struct node* root,int data)
{
    if(root == NULL)
    {
        return nodecreate(data);
    }
    if(data<root->data){
        root->l = insert(root->l,data);
    }
    else if(data>root->data){
        root->r = insert(root->r,data);
    }
    return root;
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

  
    // rooot->l=node1;
    // rooot->r=node2;

    // node1->l = node3;
    // node1->r = node4;

    // node2->l = node5;
    // node2->r = node6;

    printf("preorder traversal\n");
    preorder(rooot);
    printf("\n");
    printf("postorder traversal\n");
    postorder(rooot);
    printf("\n");
    printf("inorder traversal\n");
    inorder(rooot);


}