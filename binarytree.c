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
    struct node *rooot = nodecreate(50);
    struct node *node1 = nodecreate(3);
    struct node *node2 = nodecreate(30);
    struct node *node3 = nodecreate(20);
    struct node *node4 = nodecreate(40);
    struct node *node5 = nodecreate(60);
    struct node *node6 = nodecreate(70);

    insert(rooot,50);
    insert(rooot,3);
    insert(rooot,30);
    insert(rooot,20);
    insert(rooot,40);
    insert(rooot,60);
    insert(rooot,70);
    
    printf("preorder traversal\n");
    preorder(rooot);
    printf("\n");
    printf("postorder traversal\n");
    postorder(rooot);
    printf("\n");
    printf("inorder traversal\n");
    inorder(rooot);


}