#include<iostream>
using namespace std;

class Student
{
    private:
    int roll_no;
    string name;
    float marks;

    public:
       void set_rn()
       {
        cout<<"\nEnter Roll No:"<<endl;
        cin>>roll_no;
        cout<<"\nEnter Name:"<<endl;
        cin>>name;
       }
       void display_rn()
       {
        cout<<"\nRoll No:"<<roll_no<<"\nName:"<<name<<endl;
       }
};
class Physics
{
    protected:
       float phy;
    public:
       void get_phy(float p)
       {
        
        phy=p;
       }
      
};
class Chemistry
{
    protected:
       float chem;
    public:
       void get_chem(float c)
       {
        chem=c;
       }
      
};
class Maths
{
    protected:
       float math;
    public:
       void get_math(float m)
       {
        math=m;
       }
       
};
class Average:public Student,public Physics,public Chemistry,public Maths
{
    public:
       void display()
       {
        set_rn();
        display_rn();
        cout<<"Physics="<<phy<<endl;
        cout<<"Chemistry="<<chem<<endl;
        cout<<"Maths="<<math<<endl;
        cout<<"(phy+chem+math)/3="<<(phy+chem+math)/3<<endl;
       }
};
int main()
{
    Average a;
    a.get_phy(96.76);
    a.get_chem(95.897);
    a.get_math(98.87);
    a.display();
    return 0;
}