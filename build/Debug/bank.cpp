#include<iostream>
using namespace std;

class Account
{
 protected:
     string acc_no;
     double balance;
 public:
     double deposit;
     double withdraw;

     void set(string a,double b,double d,double w)
     {
        acc_no=a;
        balance=b;
        deposit=d;
        withdraw=w;
     }   
     int deposit()
     {
        double Total_Amount = balance + deposit;
        return Total_Amount;
        cout<<"Total Amount:"<<Total_Amount<<endl;
     }
     int withdraw()
     {
        double Total_Amount = balance - withdraw; 
        return Total_Amount;    
        cout<<"Total Amount:"<<Total_Amount<<endl;   
     }
     void display()
     {
      cout<<"Account Number"<<acc_no<<endl;
      cout<<"Total Balance:"<<balance<<endl;
     }
};

class Savingsacc:public Account
{
    private:
       double ir;
    public:
       void irate(double i)
       {
         ir=i;
       }
       int add_ir()
       {
        double Total_Amount = balance + ((ir*balance)/100);
        return Total_Amount;
        cout<<"Total Amount:"<<Total_Amount<<endl;
       }
};

class Checkacc:public Account
{
   private:
      double servchrg;
   public:
      void charge(double s)
      {
         servchrg=s;
      }
      int servicecharge()
      {
         double Total_Amount = balance - servchrg;
         return Total_Amount;
         cout<<"Total Amount:"<<Total_Amount<<endl;
      }
};

class Business:public Account
{
   private:
      char business_name;
   public:
      void display()
      {
         cout<<"Business Name : Roy Solutions"<<endl;
      }
};

int main()
{
   Savingsacc s1;
   Checkacc c1;
   Business b1;

   b1.display();
  
   string a;
   double b;
   cout<<"Enter Account No. and Balance:"<<endl;
   cin>>a>>b;
   s1.display();
   double d,w;
   cout<<"Enter the Deposit Amount:"<<endl;
   cin>>d;
   s1.deposit();
   cout<<"Enter the Withdraw Amount:"<<endl;
   cin>>w;
   s1.withdraw();
   double ir;
   cout<<"Enter the Interest Rate:"<<endl;
   cin>>ir;
   s1.add_ir();
   double s;
   cout<<"Enter the Service Charges:"<<endl;
   cin>>s;
   c1.servicecharge();
   return 0;

}
