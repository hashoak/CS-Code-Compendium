#include<stdio.h>

int main()
{
    char c;
    printf("Type the character: ");
    scanf("%c", &c);
    switch (c)
    {
        case '0':
            printf("Number");
            break;
        case '1':
            printf("Number");
            break;
        case '2':
            printf("Number");
            break;
        case '3':
            printf("Number");
            break;
        case '4':
            printf("Number");
            break;
        case '5':
            printf("Number");
            break;
        case '6':
            printf("Number");
            break;
        case '7':
            printf("Number");
            break;
        case '8':
            printf("Number");
            break;
        case '9':
            printf("Number");
            break;
        default:
            printf("Alphabet");
    }

    return 0;
}