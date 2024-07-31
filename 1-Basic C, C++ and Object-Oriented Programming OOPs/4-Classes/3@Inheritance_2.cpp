#include<iostream>
using namespace std;

class Physics
{
    public:
    float marks_physics;
};

class Chemistry
{ 
    public:
    float marks_chemistry;
};

class Maths
{
    public:
    float marks_maths;
};

class Marks: public Physics,public Chemistry,public Maths
{
    public:
    int roll_no;
    string name;
    float marks;
    void total_marks()
    {
        marks=marks_physics+marks_chemistry+marks_maths;
    }
};

int main()
{
    int n;
    cin>>n;
    Marks students[n];
    float Class_total;
    for(int i=0;i<n;i++)
    {
        students[i].roll_no=i+1;
        cin>>students[i].name;
        cin>>students[i].marks_physics;
        cin>>students[i].marks_chemistry;
        cin>>students[i].marks_maths;
        students[i].total_marks();
        Class_total+=students[i].marks;
        cout<<students[i].roll_no<<" "<<students[i].name<<" "<<students[i].marks<<"\n";
    }
    cout<<"Class average is: "<<Class_total/n<<"\n";
    return 0;
}