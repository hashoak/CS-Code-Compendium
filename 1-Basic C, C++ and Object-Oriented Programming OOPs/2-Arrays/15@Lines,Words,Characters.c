#include <stdio.h>
#include <string.h>

int main()
{
    char t[1000];
    scanf("%[^~]",&t);
    int i,l=1,w=1,c=0;
    for(i=0;t[i]!='\0';i++)
    {
        if(t[i]==' ')
        {
            w++;
        }
        else if(t[i]=='\n')
        {
            l++;
            w++;
        }
        else
        {
            c++;
        }
    }
    printf("Total number of lines: %d\n",l);
    printf("Total number of words: %d\n",w);
    printf("Total number of characters %d",c);
    return 0;
}