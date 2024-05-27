#include<iostream>
using namespace std;
class Complex 
{
  private:
    float r,i;
  public:
     Complex(float x = 0, float  y= 0)
     {
      r = x;
      i = y;
     }

     Complex operator+(Complex& c)
     {
      Complex res;
      res.r = r + c.r;
      res.i = i + c.i;
      return res;
     }
     Complex operator-(Complex& c)
     {
      Complex res;
      res.r = r - c.r;
      res.i = i - c.i;
      return res;
     }
     Complex operator*(Complex& c)
     {
      Complex res;
      res.r = (r*c.r)-(i*c.i);
      res.i = (r*c.i)+(i*c.r);
      return res;
     }
     Complex operator/(Complex& c)
     {
      Complex res;
      res.r = ((r*c.r)+(i*c.i))/((c.r * c.r) + (c.i * c.i));
      res.i = ((i*c.r)-(r*c.i))/((c.r * c.r) + (c.i * c.i));
      return res;
     }
     void print()
     {
      cout << r << " + i" << i << "\n"<<endl;
     }
};

int main()
{
  float a,b,c,d;
  cout<<"Enter Real Part of First Complex number:"<<endl;
  cin>>a;
  cout<<"\nEnter Imaginary Part of First Complex number:"<<endl;
  cin>>b;
  cout<<"\nFirst Complex Number is:"<<"\n"<<a<<" + i"<<b<<endl;
  Complex n1(a, b);
  cout<<"\nEnter Real Part of Second Complex number:"<<endl;
  cin>>c;
  cout<<"\nEnter Imaginary Part of Second Complex number:"<<endl;
  cin>>d;
  cout<<"\nSecond Complex Number is:"<<"\n"<<c<<" + i"<<d<<endl;
  Complex n2(c,d);

  cout<<"\nAddition of Complex numbers is:"<<endl;
  Complex C1 = n1 + n2;
  C1.print();
  
  cout<<"\nSubtraction of  Complex numbers is:"<<endl;
  Complex C2 = n1 - n2;
  C2.print();
  
  cout<<"\nMultiplication  of Complex numbers is:"<<endl;
  Complex C3 = n1 * n2;
  C3.print();
  
  cout<<"\nDivision of Complex  numbers is:"<<endl;
  Complex C4 = n1 / n2;
  C4.print();

  return 0;
}
