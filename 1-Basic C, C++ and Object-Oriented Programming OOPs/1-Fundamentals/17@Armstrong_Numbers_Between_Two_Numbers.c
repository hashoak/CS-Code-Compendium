#include<stdio.h>

int main()
{
    int a,b;

    printf("Type the two numbers: ");
    scanf("%d%d", &a,&b);

    int i,j,p=0;
    for(i=a+1;i<b;i++)
    {
        int x=i,k,y=0,r,d;
        for(j=0;x>0;j++)
        {
            x/=10;
        }
        d=j;
        x=i;
        for(j=0;x>0;j++)
        {
            r=x%10;
            int t=1;
            for(k=0;k<d;k++)
            {
                t*=r;
            }
            y+=t;
            x/=10;
        }

        if(i==y)
        {
            if(p){printf(",");}
            p++;
            printf("%d",y);
        }
    }

    return 0;
}