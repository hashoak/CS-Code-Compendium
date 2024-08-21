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

void display_singly(node_singly* head)
{
    for(node_singly* temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return;
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

void display_doubly(node_doubly* head)
{
    for(node_doubly* temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return;
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

void* swap(node_singly *n1,node_singly *n2)
{
    int temp=n2->data;
    n2->data=n1->data;
    n1->data=temp;
    return n2;
}

void bubbleSort(node_singly **head)
{
	if(*head==NULL) return;
	node_singly *start;
	node_singly *last=NULL;
    while(start!=*head)
	{
        start=*head;
		while(start->next!=last)
		{
			if(start->data>start->next->data)
			{
				swap(start,start->next);
			}
			start=start->next;
		}
		last=start;
	}
    return;
}

void insertionSort(node_doubly **head)
{
    if(*head==NULL) return;
    for(node_doubly *i=(*head)->next;i!=NULL;i=i->next)
    {
        int c=i->data;
        node_doubly *j=i->prev;
        while(j!=NULL && j->data>c)
        {
            j->next->data=j->data;
            if(j->prev==NULL) j->data=c;
            j=j->prev;
        }
        if(j!=NULL) j->next->data=c;
    }
}

void selectionSort(node_singly **head)
{
    if(*head==NULL) return;
    for(node_singly *i=*head;i->next!=NULL;i=i->next)
    {
        node_singly *min=i;
        for(node_singly *j=i->next;j!=NULL;j=j->next)
        {
            if(j->data<min->data) min=j;
        }
        if(min!=i) swap(min,i);
    }
    return;
}

void FrontBackSplit(node_singly* source,node_singly** frontRef,node_singly** backRef)
{
    node_singly* fast;
    node_singly* slow;
    slow=source;
    fast=source->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *frontRef=source;
    *backRef=slow->next;
    slow->next=NULL;
    return;
}

node_singly* SortedMerge(node_singly* a, node_singly* b)
{
    node_singly* result=NULL;
    if(a==NULL) return(b);
    else if(b==NULL) return(a);
    if(a->data<=b->data)
    {
        result=a;
        result->next=SortedMerge(a->next,b);
    }
    else
    {
        result=b;
        result->next=SortedMerge(a,b->next);
    }
    return(result);
}

void MergeSort(node_singly** headRef)
{
    node_singly* head=*headRef;
    node_singly* a;
    node_singly* b;
    if((head==NULL) || (head->next==NULL)) return;
    FrontBackSplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef=SortedMerge(a,b);
    return;
}

node_singly* last_node(node_singly* head)
{
    node_singly* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

node_singly* parition(node_singly* first, node_singly* last)
{
    // Get first node of given linked list
    node_singly* pivot = first;
    node_singly* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;
 
            // Swapping  node values
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            // Visiting the next node
            first = first->next;
        }
 
        // Visiting the next node
        front = front->next;
    }
 
    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}

void quickSort(node_singly* first, node_singly* last)
{
    if (first == last) {
        return;
    }
    node_singly* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quickSort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quickSort(first, pivot);
    }
}

int main()
{
    printf("Bubble sort:\n");
    node_singly *list1=create_singly(30);
    list1=insertAtHead_singly(list1,40);
    list1=insertAtHead_singly(list1,20);
    list1=insertAtHead_singly(list1,50);
    list1=insertAtHead_singly(list1,10);
    list1=insertAtHead_singly(list1,60);
    list1=insertAtHead_singly(list1,70);
    display_singly(list1);
    isSorted_singly(list1); // Bubble sort has same
    bubbleSort(&list1);     // complexity in both singly
    display_singly(list1);  // and doubly linked list.
    isSorted_singly(list1);

    printf("\nInsertion sort:\n");
    node_doubly *list2=create_doubly(30);
    list2=insertAtHead_doubly(list2,40);
    list2=insertAtHead_doubly(list2,20);
    list2=insertAtHead_doubly(list2,50);
    list2=insertAtHead_doubly(list2,10);
    list2=insertAtHead_doubly(list2,60);
    list2=insertAtHead_doubly(list2,70);
    display_doubly(list2);
    isSorted_doubly(list2); // Insertion sort is effecient in
    insertionSort(&list2);  // doubly linked list since we can't
    display_doubly(list2);  // interate back in singly linked list.
    isSorted_doubly(list2);

    printf("\nSelection sort:\n");
    list1=create_singly(30);
    list1=insertAtHead_singly(list1,40);
    list1=insertAtHead_singly(list1,20);
    list1=insertAtHead_singly(list1,50);
    list1=insertAtHead_singly(list1,10);
    list1=insertAtHead_singly(list1,60);
    list1=insertAtHead_singly(list1,70);
    display_singly(list1);
    isSorted_singly(list1); // Selection sort has same
    selectionSort(&list1);  // complexity in both singly
    display_singly(list1);  // and doubly linked list.
    isSorted_singly(list1);

    printf("\nMerge sort:\n");
    list1=create_singly(30);
    list1=insertAtHead_singly(list1,40);
    list1=insertAtHead_singly(list1,20);
    list1=insertAtHead_singly(list1,50);
    list1=insertAtHead_singly(list1,10);
    list1=insertAtHead_singly(list1,60);
    list1=insertAtHead_singly(list1,70);
    display_singly(list1);
    isSorted_singly(list1); // Merge sort has same
    MergeSort(&list1);      // complexity in both singly
    display_singly(list1);  // and doubly linked list.
    isSorted_singly(list1);

    printf("\nQuick sort:\n");
    list1=create_singly(30);
    list1=insertAtHead_singly(list1,40);
    list1=insertAtHead_singly(list1,20);
    list1=insertAtHead_singly(list1,50);
    list1=insertAtHead_singly(list1,10);
    list1=insertAtHead_singly(list1,60);
    list1=insertAtHead_singly(list1,70);
    display_singly(list1);
    isSorted_singly(list1);             // Quick sort is effecient in doubly
    quickSort(list1,last_node(list1));  // linked list since we can't
    display_singly(list1);              // interate back in singly linked list.
    isSorted_singly(list1);
    return 0;
}