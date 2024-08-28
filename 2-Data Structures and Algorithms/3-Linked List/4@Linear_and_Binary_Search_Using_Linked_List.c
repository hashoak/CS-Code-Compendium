#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node* create(int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

int isEmpty(node *head)
{
    return head==NULL;
}

node* insertAtHead(node* head,int data)
{
    node *new=create(data);
    new->next=head;
    head=new;
    return head;
}

void display(node* head)
{
    for(node* temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return;
}

int linear_search(node* head, int key)
{
    int pos=1;
    for(node *temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==key)
        {
            printf("%d is present in the list\n",key);
            return 1;
        }
        pos++;
    }
    printf("%d is not present in the list\n",key);
    return 0;
}

node* middle(node *start,node *last)
{
    if(start==NULL) return NULL;
    node *slow=start;
    node *fast=start->next;
    while(fast!=last)
    {
        fast=fast->next;
        if(fast!=last)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}

int binary_search(node *head,int value)
{
    node *start=head;
    node *last=NULL;
    do
    {
        node *mid=middle(start,last);
        if(mid==NULL) break;
        if(mid->data==value)
        {
            printf("%d is present in the list\n",value);
            return 1;
        }
        else if(mid->data<value) start=mid->next;
        else last=mid;
    } while (last==NULL || last!=start);
    printf("%d is present in the list\n",value);
    return 0;
}

int main()
{
    node *list=create(70);
    list=insertAtHead(list,60);
    list=insertAtHead(list,50);
    list=insertAtHead(list,40);
    list=insertAtHead(list,30);
    list=insertAtHead(list,20);
    list=insertAtHead(list,10);
    printf("Values in the list are:\n");
    display(list);
    printf("\nLinear search:\n");
    linear_search(list,50);
    linear_search(list,5);
    printf("\nBinary search:\n");
    binary_search(list,30);
    binary_search(list,35);
    return 0;
}