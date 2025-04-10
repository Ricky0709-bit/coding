#include<iostream>
using namespace std;

class Person
{
    private:
       string name;
       int age;
    public:
       Person(string nm,int a)
       {
        name=nm;
        age=a;
       }
    
    Person(Person &obj)
    {
        name=obj.name;
        age=obj.age;
    }
    void display()
    {
        cout<<"Name:"<<name<<"\nAge:"<<age<<endl;
    }
    
};

int main()
{
    Person p1("Hitesh",19);

    Person p2=p1;

    cout<<"Person 1:"<<endl;
    p1.display();

    cout<<"Person 2:"<<endl;
    p2.display();

    return 0;


}