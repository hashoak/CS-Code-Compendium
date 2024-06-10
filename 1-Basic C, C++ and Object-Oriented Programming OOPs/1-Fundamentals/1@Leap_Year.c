#include<stdio.h>

int main()
{
    int y;

    printf("Type the year: ");
    scanf("%d", &y);

    if(y%4){
        printf("Not Leap year");
    }
    else{
        printf("Leap year");
    }
    
    return 0;
}