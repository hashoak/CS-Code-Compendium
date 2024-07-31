#include<stdio.h>
#include<string.h>

struct MyLibrary
{
    int access;
    char title[300];
    char author[100];
    float price;
    int issued;
};

void add(struct MyLibrary *lib,int i)
{
    printf("Accession number: ");
    scanf("%d",&lib[i].access);
    printf("Title of the book: ");
    scanf(" %[^\t\n]s",lib[i].title);
    printf("Author of the book: ");
    scanf(" %[^\t\n]s",lib[i].author);
    printf("Price of the book: ");
    scanf("%f",&lib[i].price);
    printf("Type 1 if the book is issued else type 0: ");
    scanf("%d",&lib[i].issued);
    return;
}

void display(struct MyLibrary lib[],int n)
{
    int i,accno;
    printf("Type the accession number of the book: ");
    scanf("%d",&accno);
    for(i=0;i<n;i++)
    {
        if(accno==lib[i].access)
        {
            printf("Accession number: %d\nTitle of the book: %s\nName of the author: %s\nPrice of the book: Rs.%f\n\n",lib[i].access,lib[i].title,lib[i].author,lib[i].price);
            return;
        }
    }
    printf("No book found!\n");
    return;
}

void listauthor(struct MyLibrary lib[],int n)
{
    int i,b=1;
    char auth[100];
    printf("Type the name of the author: ");
    scanf(" %[^\t\n]s",auth);
    for(i=0;i<n;i++)
    {
        if(!strcmp(auth,lib[i].author)) printf("Accession number: %d\nTitle of the book: %s\n\n",lib[i].access,lib[i].title),b=0;
    }
    if(b) printf("No books found!\n\n");
    return;
}

void listbook(struct MyLibrary lib[],int n)
{
    int i,accno;
    printf("Type the accession number of the book: ");
    scanf("%d",&accno);
    for(i=0;i<n;i++)
    {
        if(accno==lib[i].access)
        {
            printf("Title of the book: %s\n\n",lib[i].title);
            return;
        }
    }
    printf("No book found!\n\n");
    return;
}

void listaccess(struct MyLibrary lib[],int n)
{
    int i,j,t;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(lib[j].access>lib[j+1].access)
            {
                t=lib[j].access;
                lib[j].access=lib[j+1].access;
                lib[j+1].access=t;
            }
        }
    }
    for(i=0;i<n;i++) printf("Accession number: %d\nTitle of the book: %s\n\n",lib[i].access,lib[i].title);
    return;
}

int main()
{
    struct MyLibrary lib[1000];
    int key=0,i=0;
    printf("Type the number to execute it's corresponding function:\n");
    printf("1. ADD Book Info\n2. Display Book info\n3. List all book of given author\n4. List the title of specified book\n");
    printf("5. List the count of books in library\n6. List the books in the order of accession number\n7. Exit.\n");
    while(1)
    {
        scanf("%d",&key);
        if(key==1) add(lib,i), i++;
        else if(key==2) display(lib,i);
        else if(key==3) listauthor(lib,i);
        else if(key==4) listbook(lib,i);
        else if(key==5) printf("There are %d books in the library.\n", i);
        else if(key==6) listaccess(lib,i);
        else if(key==7) break;
        else printf("Type valid request. Type 7 to exit.");
    }
    return 0;
}