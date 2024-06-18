#include<stdio.h>

int main()
{
    int n1,m1;
    scanf("%d%d",&n1,&m1);
    int n2,m2;
    scanf("%d%d",&n2,&m2);
    if(m1!=n2)
    {
        printf("Invalid Matrix Sizes!\n");
        return 0;
    }
    int a[n1][m1],b[n2][m2],i,j,k;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n2;i++)
    {
        for(j=0;j<m2;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    int m[n1][m2];
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m2;j++)
        {
            m[i][j]=0;
        }
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m2;j++)
        {
            int s=0;
            for(k=0;k<m1;k++)
            {
                s+=a[i][k]*b[k][j];
            }
            m[i][j]=s;
        }
    }
    printf("\nThe multiplication of two matrix is:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m2;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}