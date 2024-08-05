#include<iostream>
using namespace std;

class article
{
    public:
    string title,author;
    int year,charge;
    void get_article()
    {
        cin>>title>>author>>year;
    }
};

class printed_article: public article
{
    int ISBN,chapter,starting,ending;
    public:
    void get()
    {
        this->get_article();
        cin>>ISBN>>chapter>>starting>>ending;
    }
    void calculate_Charge()
    {
        charge=(ending-starting+1)*1000;
    }
    void print()
    {
        cout<<"Article title: "<<title<<", Author: "<<author<<", Year of publication: "<<year;
        cout<<", ISBN number: "<<ISBN<<", Publication Charge: "<<charge<<"\n";
    }
};

class online_article: public article
{
    int eISBN,volume,pages;
    public:
    void get()
    {
        this->get_article();
        cin>>eISBN>>volume>>pages;
    }
    void calculate_Charge()
    {
        charge=(pages+2)/3*5000;
    }
    void print()
    {
        cout<<"Article title: "<<title<<", Author: "<<author<<", Year of publication: "<<year;
        cout<<", e-ISBN number: "<<eISBN<<", Publication Charge: "<<charge<<"\n";
    }
};

int main()
{
    printed_article p;
    online_article o;
    p.get();
    o.get();
    p.calculate_Charge();
    o.calculate_Charge();
    p.print();
    o.print();
    return 0;
}