#include<iostream>
using namespace std;

class Mammal
{
    public:
    void print_mammal()
    {
        cout<<"I am a Mammal\n";
    }
};

class Marine_Animal
{
    public:
    void print_marine()
    {
        cout<<"I am a Marine Animal\n";
    }
};

class Blue_Whale: public Mammal,public Marine_Animal
{
    public:
    void print_whale()
    {
        cout<<"I belong to both the categories, Mammals as well as Marine Animals\n";
    }
};

int main()
{
    Mammal elephant;
    Marine_Animal shark;
    Blue_Whale whale;
    elephant.print_mammal();
    shark.print_marine();
    whale.print_whale();
    whale.print_mammal();
    whale.print_marine();
    return 0;
}