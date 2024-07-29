#include<iostream>
using namespace std;

class Apples
{
    public:
    int number_apples;
    void print_apples()
    {
        cout<<"There are "<<number_apples<<" Apples\n";
    }
};

class Mangoes
{
    public:
    int number_mangoes;
    void print_mangoes()
    {
        cout<<"There are "<<number_mangoes<<" Mangoes\n";
    }
};

class Fruits: public Mangoes,public Apples
{
    public:
    void get_apples(int a)
    {
        number_apples=a;
    }
    void get_mangoes(int m)
    {
        number_mangoes=m;
    }
    void print_fruits()
    {
        cout<<"There are "<<number_apples+number_mangoes<<" Fruits\n";
    }
};

int main()
{
    Fruits f;
    cin>>f.number_apples;
    cin>>f.number_mangoes;
    f.print_apples();
    f.print_mangoes();
    f.print_fruits();
    return 0;
}