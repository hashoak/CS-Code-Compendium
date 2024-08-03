#include<stdio.h>

int main()
{
    int m;
    scanf("%d",&m);
    while(m>=0 && m<=100)
    {
        int t=m/10,o=m%10;
        if(t==10) printf("Hundred");
        else if(t==9) printf("Ninty ");
        else if(t==8) printf("Eighty ");
        else if(t==7) printf("Seventy ");
        else if(t==6) printf("Sixty ");
        else if(t==5) printf("Fifty ");
        else if(t==4) printf("Fourty ");
        else if(t==3) printf("Thirty ");
        else if(t==2) printf("Twenty ");
        else if(t==1)
        {
            if(o==1) printf("Eleven");
            else if(o==2) printf("Twelve");
            else if(o==3) printf("Thirteen");
            else if(o==4) printf("Fourteen");
            else if(o==5) printf("Fifteen");
            else if(o==6) printf("Sixteen");
            else if(o==7) printf("Seventeen");
            else if(o==8) printf("Eighteen");
            else if(o==9) printf("Nineteen");
            else printf("Ten");
        }
        if(t!=10 && t!=1)
        {
            if(o==9) printf("Nine");
            else if(o==8) printf("Eight");
            else if(o==7) printf("Seven");
            else if(o==6) printf("Six");
            else if(o==5) printf("Five");
            else if(o==4) printf("Four");
            else if(o==3) printf("Three");
            else if(o==2) printf("Two");
            else if(o==1) printf("One");
            else if(t==0) printf("Zero");
        }
        printf("\n");
        scanf("%d",&m);
    }
    printf("Enter valid marks");
    return 0;
}