#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node* create(int x)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    return new;
}

node* insertAtTailcirc(node* head,int val)
{
    node *n=create(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return head;
    }
    node* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=n;
    n->next=head;
    return head;
}

node* insertAtHeadcirc(node* head,int val)
{
    node *n=create(val);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return head;
    }
    node* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=n;
    n->next=head;
    head=n;
    return head;
}

int length_circ(node* head)
{
    int n=0;
    node* temp=head;
    do
    {
        n++;
        temp=temp->next;
    }while(temp!=head);
    return n;
}

int main()
{
    node* head=NULL;
    head=insertAtTailcirc(head,1);
    head=insertAtTailcirc(head,2);
    head=insertAtTailcirc(head,3);
    head=insertAtHeadcirc(head,4);
    head=insertAtHeadcirc(head,5);
    printf("Length of the circular list is %d",length_circ(head));
    return 0;
}