#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s",s);
    int i,l=strlen(s);
    for(i=0;i<=l/2;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            printf("Not Palindrome");
            break;
        }
    }
    if(i>l/2)
    {
        printf("Palindrome");
    }
    return 0;
}