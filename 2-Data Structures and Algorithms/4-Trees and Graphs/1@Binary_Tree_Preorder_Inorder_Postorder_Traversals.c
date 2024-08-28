#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
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

int main()
{
    node* root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    root->right->left=create(6);
    root->right->right=create(7);
    /*
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
    */
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}