#include<iostream>
#include<fstream>
#include"bat.h"
#include"rent.h"
using namespace std;

class temp
{
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
   public:
    int w=0;
    int login();
    void signUP();
    void forgot();
}obj;

int main()
{
    BookTrip b;
    int t;
    char choice;
    do
    {
        cout<<"\n\t\t---------------------------------WELCOME To RidesGo...---------------------------------\t\t\n"<<endl;
        cout<<"\n1- Login"<<endl;
        cout<<"\n2- Sign-Up"<<endl;
        cout<<"\n3- Forgot Password?"<<endl;
        cout<<"\n4- Exit"<<endl;
        cout<<"\nEnter Your Choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
            case '1':
                cin.ignore();
                t=obj.login();
                do{
                if(t==1)
                {
                cout<<"\n1- Book a Ride"<<endl;
                cout<<"\n2- Rent a Vehicle"<<endl;
                cout<<"\nPress 0 to Go BAck"<<endl;
                cout<<"\nEnter Your Choice : "<<endl;
                }
                else
                obj.login();
                }
                while(t!=1);
                int m;
                cin>>m;
                if(m==1)
                {
                    
                    system("Cls");
                    cout<<"\n              Welcome to Cab Booking System              \n"<<endl;
                    b.data();
                    b.menu();
                    int ch;
                    b.Details(ch);
                    char decide;
                    cout<<"\n\t\t                 Do you want to continue?:(y/n)                \t\t\n"<<endl;
                    cin>>decide;
                    char y;
                    if(decide=='y')
                    {
                     system("Cls");
                     cout<<"\n\t\t                 Cab Booked Successfully...!!!                   \t\t\n"<<endl;
                     cout<<"\n\t\t                       Thank You...!                       \t\t\n"<<endl;
                    }
                    else
                    {
                     system("Cls");   
                     cout<<"\n\t\t                    Booking Failed !!!                   \t\t\n"<<endl;
                     cout<<"\n\t\t                        Try Again.                       \t\t\n"<<endl;
                    }
                }
                if(m==2)
                {
                 Vehicle vh;
                system("Cls");
                cout<<"\n              Welcome to Vehicle Rental System              \n"<<endl;
                int v;
                vh.vmenu();
                int x,z;
                vh.Details(x,z);
                char decide;
                cout<<"\n\t\t                 Do you want to continue?:(y/n)                \t\t\n"<<endl;
                cin>>decide;
                char y;
                if(decide=='y')
                {
                 system("Cls"); 
                 cout<<"\n\t\t                 Vehicle Rented Successfully...!!!                   \t\t\n"<<endl;
                 cout<<"\n\t\t                       Thank You...!                       \t\t\n"<<endl;
                }
                else
                {
                 system("Cls"); 
                 cout<<"\n\t\t                         Failed !!!                   \t\t\n"<<endl;
                 cout<<"\n\t\t                         Try Again.                   \t\t\n"<<endl;
                 vh.vmenu();
                }
               }
               else
               {
                main();
               } 
                break;
            case '2':
                cin.ignore();
                obj.signUP();
                break;
            case '3':
                cin.ignore();
                obj.forgot();
                break;
            case '4':
                cout<<"\nSigned Out...!"<<endl;
                exit(4);
                break;
            default:
                cout<<"\nInvalid Choice...! Try Again."<<endl;
                break;
        }
        } while (choice!='4');

}

void temp::signUP()
{
    cout << "\nEnter Your User Name : " << endl;
    getline(cin, userName);
    cout << "Enter Your Email Address : " << endl;
    getline(cin, Email);
    cout << "Enter Your Password : " << endl;
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (!file.is_open()) 
    {
        cerr << "Cannot open file." << endl;
        return;
    }

    if (!(file << userName << "*" << Email << "*" << password << endl)) 
    {
        cerr << "\nError writing to file." << endl;
        file.close();
        return;
    }

    cout << "\n Signed Up Successfully...!!!" << endl;
    file.close(); 
}


int temp::login()
{
   
    cout<<"\n\t-------------------------------------LOGIN------------------------------------\t\n"<<endl;
    cout<<"Enter Your User Name : "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password : "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt", ios::in);
    if (!file) 
    {
        cerr << "Cannot open file." << endl;
        return 1;
    }
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) 
    {
        if (userName == searchName && password == searchPass) 
        {
            system("CLS");
            cout<<"\n LOGIN Successful...!!!\n";
            cout<<"\nUsername : "<<userName<<endl;
            cout<<"\nEmail : "<<Email<<endl;
            found = true;
            w=1;
            return w;
            break;
        }
    }
    if (!found) 
    {
        cout<<"\nLOGIN ERROR \nPlease check your username and password.\n";
    }
    file.close();
}
void temp::forgot()
{
    cout<<"\nEnter Your UserName : "<<endl;
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address : "<<endl;
    getline(cin,searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) 
    {
        cerr << "Cannot open file." << endl;
        return;
    }
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) 
    {
        if (userName == searchName && Email == searchEmail) 
        {
            cout<<"\nAccount Found...!"<<endl;
            cout<<"\nYour Password : "<<password<<endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        system("CLS");
        cout<<"Error! 404 Not found...!\n";
    }
    file.close();
}
