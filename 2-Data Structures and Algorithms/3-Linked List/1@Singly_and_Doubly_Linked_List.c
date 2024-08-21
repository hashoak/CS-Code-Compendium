#include<stdio.h>
#include<stdlib.h>

struct Node_singly
{
    int data;
    struct Node_singly *next;
};

typedef struct Node_singly node_singly;

node_singly* create_singly(int data)
{
    node_singly *temp=(node_singly*)malloc(sizeof(node_singly));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

int isEmpty_singly(node_singly *head)
{
    return head==NULL;
}

node_singly* insertAtHead_singly(node_singly* head,int data)
{
    node_singly *new=create_singly(data);
    new->next=head;
    head=new;
    return head;
}

void insertAtMiddle_singly(node_singly *head,int data,int loc)
{
    node_singly *new=create_singly(data);
    node_singly *temp=head;
    while(temp!=NULL && temp->data!=loc) temp=temp->next;
    if(temp!=NULL)
    {
        new->next=temp->next;
        temp->next=new;
    }
    return;
}

void insertAtTail_singly(node_singly *head,int data)
{
    node_singly *new=create_singly(data);
    if(head==NULL)
    {
        head=new;
        return;
    }
    node_singly *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=new;
    return;
}

node_singly* deleteAtHead_singly(node_singly *head)
{
    if(head==NULL) return NULL;
    node_singly *del=head;
    head=head->next;
    free(del);
    return head;
}

node_singly* deleteAtMiddle_singly(node_singly* head,int val)
{
    if(head==NULL) return NULL;
    node_singly *temp=head;
    node_singly *del;
    if(temp->data==val)
    {
        del=head;
        head=temp->next;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->data==val)
        {
            del=temp->next;
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    free(del);
    return head;
}

void deleteAtTail_singly(node_singly *head)
{
    if(head==NULL) return;
    node_singly *temp=head;
    while(temp->next!=NULL && temp->next->next!=NULL) temp=temp->next;
    deleteAtHead_singly(temp->next);
    return;
}

int search_singly(node_singly* head, int key)
{
    int pos=1;
    for(node_singly *temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==key)
        {
            return pos;
        }
        pos++;
    }
    return 0;
}

void display_singly(node_singly* head)
{
    for(node_singly* temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return;
}

int length_singly(node_singly *head)
{
    int len=0;
    for(node_singly *temp=head;temp!=NULL;temp=temp->next) len++;
    return len;
}

void isSorted_singly(node_singly *head)
{
    if(isEmpty_singly(head)) return;
    int asc=1,des=1;
    for(node_singly*temp=head;asc && temp->next!=NULL;temp=temp->next)
    {
        asc=(temp->data<=temp->next->data);
    }
    for(node_singly*temp=head;des && temp->next!=NULL;temp=temp->next)
    {
        des=(temp->data>=temp->next->data);
    }
    if(asc && des) printf("All the elements are equal\n");
    else if(asc) printf("The list is sorted in ascending order\n");
    else if(des) printf("The list is sorted in descending order\n");
    else printf("The list is not sorted\n");
    return;
}

struct Node_doubly
{
    int data;
    struct Node_doubly *prev;
    struct Node_doubly *next;
};

typedef struct Node_doubly node_doubly;

node_doubly* create_doubly(int data)
{
    node_doubly *temp=(node_doubly*)malloc(sizeof(node_doubly));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

int isEmpty_doubly(node_doubly *head)
{
    return head==NULL;
}

node_doubly* insertAtHead_doubly(node_doubly* head,int data)
{
    node_doubly *new=create_doubly(data);
    new->next=head;
    if(head!=NULL) head->prev=new;
    head=new;
    return head;
}

void insertAtMiddle_doubly(node_doubly *head,int data,int loc)
{
    node_doubly *new=create_doubly(data);
    node_doubly *temp=head;
    while(temp!=NULL && temp->data!=loc) temp=temp->next;
    if(temp!=NULL)
    {
        new->next=temp->next;
        temp->next=new;
        new->prev=temp;
    }
    return;
}

void insertAtTail_doubly(node_doubly *head,int data)
{
    node_doubly *new=create_doubly(data);
    if(head==NULL)
    {
        head=new;
        return;
    }
    node_doubly *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=new;
    new->prev=temp;
    return;
}

node_doubly* deleteAtHead_doubly(node_doubly *head)
{
    if(head==NULL) return NULL;
    node_doubly *del=head;
    head=head->next;
    if(head!=NULL) head->prev=NULL;
    free(del);
    return head;
}

node_doubly* deleteAtMiddle_doubly(node_doubly* head,int val)
{
    if(head==NULL) return NULL;
    node_doubly *temp=head;
    node_doubly *del;
    if(temp->data==val)
    {
        del=head;
        head=temp->next;
        if(head!=NULL) head->prev=NULL;
    }
    while(temp->next!=NULL)
    {
        if(temp->next->data==val)
        {
            del=temp->next;
            temp->next=temp->next->next;
            if(temp->next!=NULL) temp->next->prev=temp;
            break;
        }
        temp=temp->next;
    }
    free(del);
    return head;
}

void deleteAtTail_doubly(node_doubly *head)
{
    if(head==NULL) return;
    node_doubly *temp=head;
    while(temp->next!=NULL && temp->next->next!=NULL) temp=temp->next;
    node_doubly *del=temp->next;
    temp->next=NULL;
    free(del);
    return;
}

int search_doubly(node_doubly* head, int key)
{
    int pos=1;
    for(node_doubly *temp=head;temp!=NULL;temp=temp->next)
    {
        if(temp->data==key)
        {
            return pos;
        }
        pos++;
    }
    return 0;
}

void display_doubly(node_doubly* head)
{
    for(node_doubly* temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return;
}

int length_doubly(node_doubly *head)
{
    int len=0;
    for(node_doubly *temp=head;temp!=NULL;temp=temp->next) len++;
    return len;
}

void isSorted_doubly(node_doubly *head)
{
    if(isEmpty_doubly(head)) return;
    int asc=1,des=1;
    for(node_doubly *temp=head;asc && temp->next!=NULL;temp=temp->next)
    {
        asc=(temp->data<=temp->next->data);
    }
    for(node_doubly *temp=head;des && temp->next!=NULL;temp=temp->next)
    {
        des=(temp->data>=temp->next->data);
    }
    if(asc && des) printf("All the elements are equal\n");
    else if(asc) printf("The list is sorted in ascending order\n");
    else if(des) printf("The list is sorted in descending order\n");
    else printf("The list is not sorted\n");
    return;
}

int main()
{
    printf("Operations on Singly linked list:\n");
    node_singly *list1=create_singly(10);
    display_singly(list1);
    list1=insertAtHead_singly(list1,20);
    display_singly(list1);
    list1=insertAtHead_singly(list1,30);
    display_singly(list1);
    isSorted_singly(list1);
    insertAtMiddle_singly(list1,40,30);
    display_singly(list1);
    insertAtMiddle_singly(list1,50,20);
    display_singly(list1);
    insertAtMiddle_singly(list1,60,10);
    display_singly(list1);
    printf("20 is at node %d\n",search_singly(list1,20));
    insertAtMiddle_singly(list1,60,70);
    display_singly(list1);
    insertAtTail_singly(list1,70);
    display_singly(list1);
    printf("Length of the list is %d\n",length_singly(list1));
    isSorted_singly(list1);
    list1=deleteAtHead_singly(list1);
    display_singly(list1);
    list1=deleteAtMiddle_singly(list1,40);
    display_singly(list1);
    list1=deleteAtMiddle_singly(list1,10);
    display_singly(list1);
    list1=deleteAtMiddle_singly(list1,70);
    display_singly(list1);
    list1=deleteAtMiddle_singly(list1,70);
    display_singly(list1);
    printf("Length of the list is %d\n",length_singly(list1));
    isSorted_singly(list1);

    printf("\nOperations on Doubly linked list:\n");
    node_doubly *list2=create_doubly(10);
    display_doubly(list2);
    list2=insertAtHead_doubly(list2,20);
    display_doubly(list2);
    list2=insertAtHead_doubly(list2,30);
    display_doubly(list2);
    isSorted_doubly(list2);
    insertAtMiddle_doubly(list2,40,30);
    display_doubly(list2);
    insertAtMiddle_doubly(list2,50,20);
    display_doubly(list2);
    insertAtMiddle_doubly(list2,60,10);
    display_doubly(list2);
    printf("20 is at node %d\n",search_doubly(list2,20));
    insertAtMiddle_doubly(list2,60,70);
    display_doubly(list2);
    insertAtTail_doubly(list2,70);
    display_doubly(list2);
    printf("Length of the list is %d\n",length_doubly(list2));
    isSorted_doubly(list2);
    list2=deleteAtHead_doubly(list2);
    display_doubly(list2);
    list2=deleteAtMiddle_doubly(list2,40);
    display_doubly(list2);
    list2=deleteAtMiddle_doubly(list2,10);
    display_doubly(list2);
    list2=deleteAtMiddle_doubly(list2,70);
    display_doubly(list2);
    list2=deleteAtMiddle_doubly(list2,70);
    display_doubly(list2);
    printf("Length of the list is %d\n",length_doubly(list2));
    isSorted_doubly(list2);
    return 0;
}