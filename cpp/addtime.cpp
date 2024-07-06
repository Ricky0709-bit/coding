#include<iostream>
using namespace std;

class Time
{
    private:
       int hrs;
       int min;
       int sec;
    public:
       Time(int h=0,int m=0,int s=0):hrs(h),min(m),sec(s){}

       void input_Time()
       {
        cout<<"Enter time(hh mm ss):"<<endl;
        cin>>hrs>>min>>sec;
       }
       Time add_Times( Time& rem)
       {
        int total_sec = sec + rem.sec;
        int carry_min = total_sec/60;
        total_sec %= 60;

        int total_min = min + rem.min + carry_min;
        int carry_hrs = total_min/60;
        total_min %= 60;

        int total_hrs = hrs + rem.hrs + carry_hrs;
        total_hrs %=60;

        return Time(total_hrs,total_min,total_sec);
       }
       void display_Time() 
       {
         cout<<"Resultant time:"<<hrs<<":"<<min<<":"<<sec<<":"<<endl;
       }
};

int main()
{
     Time t1,t2,result;
     
     cout<<"Enter first time:\n"<<endl;
     t1.input_Time();
     
     cout<<"Enter second time:\n"<<endl;
     t2.input_Time();

     result = t1.add_Times(t2);
     result.display_Time();
    
    return 0;

}



    
