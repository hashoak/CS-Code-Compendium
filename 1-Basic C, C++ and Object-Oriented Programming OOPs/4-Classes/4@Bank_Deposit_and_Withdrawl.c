#include<stdio.h>

struct customer
{
    char acc_no[100];
    char name[100];
    float bal;
};

void below100cust(struct customer info[],int n)
{
    int i;
    printf("Customers having balance below Rs.100:\n");
    for(i=0;i<n;i++)
    {
        if(info[i].bal<100.0)
        {
            printf("%s %s\n",info[i].acc_no,info[i].name);
        }
    }
    printf("\n");
    return;
}

void withdrawl(struct customer info[],int n)
{
    int i,dw,a;
    for(i=0;i<n;i++)
    {
        scanf("%d",&dw);
        scanf("%d",&a);
        if(dw) info[i].bal+=a;
        else if(info[i].bal-a<100) printf("%s, your balance is insufficient for the specified withdrawl.\n",info[i].name);
        else info[i].bal-=a;
    }
    return;
}

int main()
{
    struct customer info[200];
    printf("Type the number of customers\n");
    int n,i;
    scanf("%d",&n);
    printf("Type account number, name and balance of each customer\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",info[i].acc_no);
        scanf("%s",info[i].name);
        scanf("%f",&info[i].bal);
    }
    below100cust(info,n);
    printf("Type 0 if deposit or 1 if withdrawl and type the deposit or withdrwal amount\n");
    withdrawl(info,n);
    return 0;
}