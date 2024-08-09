#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    int roll_no;
    char* name;
    float marks;
    char grade;
};
typedef struct Student Student;

Student* create(int new_roll_no,char* new_name,float new_marks)
{
    Student *s=(Student*)malloc(sizeof(Student));
    s->roll_no=new_roll_no;
    s->name=(char*)malloc(100*sizeof(char));
    strcpy(s->name,new_name);
    s->marks=new_marks;
    return s;
}

int main()
{
    int n,i;
    printf("Enter the total number of students: ");
    scanf("%d",&n);
    Student **students=(Student**)malloc(n*sizeof(Student*));
    int roll_no;
    char* name;
    float marks;
    printf("Enter the roll number,name and marks of the students:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %s %f",&roll_no,name,&marks);
        students[i]=create(roll_no,name,marks);
        if(students[i]->marks>80) students[i]->grade='A';
        else if(students[i]->marks>40) students[i]->grade='B';
        else students[i]->grade='F';
    }

    int good=0,avg=0,fail=0;
    while(i>0)
    {
        i--;
        switch(students[i]->grade)
        {
        case 'A':
            good++;
            break;
        case 'B':
            avg++;
            break;
        default:
            fail++;
            break;
        }
    }
    printf("\n%d student(s) performed good, %d performed average and %d failed\n",good,avg,fail);

    printf("\nNames of the students who are failed:\n");
    do
    {
        if(students[i]->grade=='F')
        {
            printf("%s\n",students[i]->name);
        }
        i++;
    }while(i<n);
    return 0;
}