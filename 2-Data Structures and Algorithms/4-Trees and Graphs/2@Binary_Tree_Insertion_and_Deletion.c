#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node* create(int val)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void preorder(node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}

void postorder(node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    return;
}

node* insert(node* root,int val)
{
    if(root==NULL) return create(val);
    if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}

node* minVal(node *root)
{
    node *current=root;
    while(current && current->left!=NULL) current=current->left;
    return current;
}

node* delete(node* root,int key)
{
    if(root == NULL) return root;
    if(key<root->data) root->left=delete(root->left,key);
    else if(key>root->data) root->right=delete(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        node *temp=minVal(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}

int main()
{
    node* root=NULL;
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,2);
    root=insert(root,5);
    printf("After inserting 4,1,6,3,7,2 and 5:\n");
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    root=delete(root,6);
    printf("\nAfter deleting 6:\n");
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}