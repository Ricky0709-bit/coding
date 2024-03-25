#include<iostream>
using namespace std;

class Account
{
 protected:
     string acc_no;
     double balance;
 public:
     Account(string a, double b): acc_no(a), balance(b) {}  

     void deposit(double d)
     {
      balance += d;
     }
     void withdraw(double w)
     {
      if(balance >= w)
      {
         balance -= w;
      }
      else
      {
         cout<<"\nInsufficient balance!!!"<<endl;
      }
     }
     void display()
     {
      cout<<"\nAccount Number: "<<acc_no<<endl;
      cout<<"Total Balance: "<<balance<<endl;
     }
};

class Savingsacc : public Account
{
    private:
       double ir;
    public:
       Savingsacc(string a, double b, double i): Account(a, b), ir(i) {}
       
       void add_ir()
       {
        balance += balance * ir;
       }
};

class Checkacc : public Account
{
   private:
      double servchrg;
   public:
      Checkacc(string a, double b, double s): Account(a, b), servchrg(s) {}
      void servicecharge()
      {
         balance -= servchrg;
      }
};

class Business : public Account
{
   private:
      string business_name;
   public:
      Business(string a, double b, string bs): Account(a, b), business_name(bs) {}
      void display()
      {
         Account::display();
         cout<<"Business Name: "<<business_name<<endl;
      }
};

int main()
{
  string acc_no;
  double balance, interest_rate, service_charge;
  string business_name;

  
  cout << "Enter Savings Account details:" << endl;
  cout << "Account Number: ";
  cin >> acc_no;
  cout << "Initial Balance: ";
  cin >> balance;
  cout << "Interest Rate (%): ";
  cin >> interest_rate;

  Savingsacc saving(acc_no, balance, interest_rate / 100.0);
  saving.deposit(50000);
  saving.add_ir();
  saving.display();


  cout << "\nEnter Checking Account details:" << endl;
  cout << "Account Number: ";
  cin >> acc_no;
  cout << "Initial Balance: ";
  cin >> balance;
  cout << "Service Charge: ";
  cin >> service_charge;

  Checkacc check(acc_no, balance, service_charge);
  check.withdraw(500000);
  check.servicecharge();
  check.display();

  
  cout << "\nEnter Business Account details:" << endl;
  cout << "Account Number: ";
  cin >> acc_no;
  cout << "Initial Balance: ";
  cin >> balance;
  cout << "Business Name: ";
  cin>> business_name;

  Business busi(acc_no, balance, business_name);
  busi.deposit(100000);
  busi.display();

  return 0;
}
