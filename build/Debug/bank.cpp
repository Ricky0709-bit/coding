#include<iostream>
using namespace std;

class Account
{
 protected:
     string acc_no;
     double balance;
 public:
     Account(string a,double b): acc_no(a),balance(b){}  

     void deposit(double d)
     {
      balance += d;
     }
     void withdraw(double w)
     {
      if(balance>= w)
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
      cout<<"\nAccount Number"<<acc_no<<endl;
      cout<<"\nTotal Balance:"<<balance<<endl;
     }
};

class Savingsacc:public Account
{
    private:
       double ir;
    public:
       Savingsacc(string a,double b,double i):Account(a,b), ir(i) {}
       
       void add_ir()
       {
        balance += balance * ir;
       }
};

class Checkacc:public Account
{
   private:
      double servchrg;
   public:
      Checkacc(string a,double b,double s):Account(a,b),servchrg(s) {}
      void servicecharge()
      {
         balance -= servchrg;
      }
};

class Business:public Account
{
   private:
      string business_name;
   public:
      Business(string a,double b,string bs):Account(a,b),business_name(bs) {}
      void display()
      {
         Account::display();
         cout<<"\nBusiness Name :"<<business_name<<endl;
      }
};

int main()
{
  Savingsacc saving("HSX54553",150000,0.5);
  Checkacc check("HSX67867",100000,0);
  Business busi("HSX47589",120000,"Roy Solutions");

  saving.deposit(50000);
  saving.add_ir();
  saving.display();

  check.withdraw(500000);
  check.servicecharge();
  check.display();

  busi.deposit(100000);
  busi.display();

  return 0;
}
