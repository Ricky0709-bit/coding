#include<iostream>
using namespace std;

class Shape
{
    public:
       virtual double cal_area()=0;

};
    class Rectangle: public Shape
    {
        private:
           float len;
           float brd;
        public:
              Rectangle(float len,float brd):len(len),brd(brd){}
        
        double cal_area()
        {
            return len*brd;
        }
    };
    class Circle: public Shape
    {
        private:
           float radius;
        public:
           Circle(float radius):radius(radius){}
        
        double cal_area()
        {
            return 3.1425*radius*radius;
        }
    };

int main()
{
    Rectangle rect(65.75,34.89);
    Circle cir(45.26);

    cout<<"Area of rectangle:"<<rect.cal_area()<<endl;
    cout<<"Area of circle:"<<cir.cal_area()<<endl;

    return 0;

}