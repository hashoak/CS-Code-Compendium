#include<iostream>
using namespace std;

void FindStudentsBasedOnBlock();

class Hostel
{
    public:
    string blockName;
    int roomNumber;
    string AC,Veg;
};

class Student
{
    string regno,name,phno;
    Hostel h;
    public:
    static int Total_Instances;
    void setStudentDetails()
    {
        cin>>regno>>name>>phno>>h.blockName>>h.roomNumber>>h.AC>>h.Veg;
        Total_Instances++;
    }
    void getStudentDetails()
    {
        cout<<regno<<", ";
    }
    friend void FindStudentsBasedOnBlock(Student*,int,string);
};

int Student::Total_Instances=0;

void FindStudentsBasedOnBlock(Student* s,int n,string s_block)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(s[i].h.blockName==s_block) s[i].getStudentDetails(), x++;
    }
    cout<<x<<" out of "<<n<<" students belong to "<<s_block<<"\n";
}

int main()
{
    int n=3;
    Student s[n];
    for(int i=0;i<n;i++)
    {
        s[i].setStudentDetails();
    }
    string s_block;
    cin>>s_block;
    FindStudentsBasedOnBlock(s,n,s_block);
    return 0;
}