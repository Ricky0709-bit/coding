#include<iostream>
using namespace std;

inline double Areatriangle(double b,double h)
{
    return 0.5*b*h;
};
int main()
{
    double bs,ht;
    cout<<"enter base and height :"<<endl;
    cin>>bs>>ht;
    cout<<"Area of triangle is"<<Areatriangle(bs,ht);
    return 0;
}