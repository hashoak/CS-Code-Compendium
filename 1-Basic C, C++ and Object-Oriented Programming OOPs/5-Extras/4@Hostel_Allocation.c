#include<stdio.h>

struct stud
{
    char name[100];
    char regno[10];
    char block;
    int room_no;
};

void read(struct stud *s)
{
    scanf("%s",s->name);
    scanf("%s",s->regno);
}

void allocate(struct stud *s)
{
    static char r_block='A';
    static int r_room_no=1;
    s->block=r_block;
    s->room_no=r_room_no;
    r_room_no++;
    if(r_room_no>1000)
    {
        r_room_no=1;
        if(r_block=='A') r_block='B';
        else if(r_block=='B') r_block='C';
        else if(r_block=='C') r_block='D';
        else if(r_block=='D') r_block='E';
    }
}

void print(struct stud *s)
{
    printf("Reg.no: %s, Block: %c, Room number: %d\n",s->regno,s->block,s->room_no);
}

int main()
{
    struct stud s1,s2;
    read(&s1);
    read(&s2);
    allocate(&s1);
    allocate(&s2);
    print(&s1);
    print(&s2);
    return 0;
}