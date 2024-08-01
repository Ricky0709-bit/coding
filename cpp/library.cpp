#include<iostream>
using namespace std;

class Library
{
    protected:
       string name;
       int age;
    public:
       void lib()
       {
        cout<<"Name : ";
        cin>>name;
        cout<<"Age : "<<endl;
        cin>>age;
       }
};

class Employee:public Library
{
  protected:
      string emp_id;
      string designation;
  public:
      void emp()
      {
            cout<<"\nEnter Employee ID: ";
            cin>>emp_id;
            cout<<"Enter Designation: ";
            cin>>designation;
      }
      void emp_d() 
     {
     cout<<"\nName:"<<name;
     cout<<"\nAge:"<<age;
     cout << "\nEmployee ID: " << emp_id << endl;
     cout << "\nDesignation: " << designation << endl;
     }
};

class Student:public Library
{
    protected:
        string stud_id;
        string course;  
    public:
        void gstud()
    {
       cout<<"\nStudent ID: ";
       cin>>stud_id;
       cout<<"Enter Course: ";
       cin>>course; 
    }
    void stud_d()
     {
      cout<<"\nName:"<<name<<endl;
      cout<<"\nAge:"<<age<<endl;
      cout << "\nStudent ID: " << stud_id <<  endl;
      cout << "\nCourse: " << course <<  endl;
    }
};

class Book:public Employee,public Student
{
    public:
        string title;
        string book_id;
        int user_id;
        

    void manage_book(int op)
    {
    if (op == 1)
    {
        
        cout << "\nEnter user ID: ";
        cin >> user_id;
        cout<<"\nTitle:"<<endl;
        cin>>title;
        cout << "\nEnter book ID: ";
        cin >> book_id;
        cout<<"Successfully Borrowed......";
        
    }
    else 
    {
       cout << "\nEnter user ID: ";
        cin >> user_id;
        cout<<"\nTitle:"<<endl;
        cin>>title;
        cout << "\nEnter book ID: ";
        cin >> book_id;
        cout<<"Successfully Returned";
    }
    }
};

int main()
{
  Employee e;
  Student s;
  Book b;
  int bo;
  int c;
  cout<<"1.Employee \n 2. Student:"<<endl;
  cin>>c;
 
  if (c == 1) 
   {
        e.lib();
        e.emp();
        e.emp_d();
        cout<<"\n1.Borrow \n 2.Return\n ";
        cin>>bo;
        b.manage_book(bo);
    } 
    else if (c == 2) 
    {
        s.lib();
        s.gstud();
        s.stud_d();
         cout<<"\n1.Borrow \n 2.Return\n ";
        cin>>bo;
        b.manage_book(bo);
    } 
    else 
    {
        cout << "Invalid choice" << endl;
        return 1;
    }

  return 0;
}
