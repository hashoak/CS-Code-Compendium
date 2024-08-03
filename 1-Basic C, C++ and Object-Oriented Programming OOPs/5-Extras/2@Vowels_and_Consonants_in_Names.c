#include<stdio.h>
#include<string.h>

void read_Students();
void calculate_Students();
void print_Students();

int main()
{
    read_Students();
    return 0;
}

void read_Students()
{
    int n=0,i,j=0;
    char names[10][100];
    for(i=0;i<10;i++)
    {
        char name[100];
        scanf("%s",name);
        if(name[0]=='A' ||name[0]=='E' ||name[0]=='I' ||name[0]=='O' ||name[0]=='U')
        {
            printf("%s\n",name);
            strcpy(names[j++],name);
            n++;
        }
    }
    if(n==0) printf("No student name with starting letter as vowel\n");
    for(int i=0;i<n;i++)
    {
        calculate_Students(names[i]);
    }
}

void calculate_Students(char name[])
{
    int c=0,v=1,i;
    for(i=1;name[i]!='\0';i++)
    {
        if(name[i]=='a' ||name[i]=='e' ||name[i]=='i' ||name[i]=='o' ||name[i]=='u')
        {
            v++;
        }
        else c++;
    }
    print_Students(name,c,v);
    return;
}

void print_Students(char name[],int c,int v)
{
    printf("%s: no.of vowels %d, no.of consonats %d\n",name,v,c);
    return;
}