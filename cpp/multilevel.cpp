#include<iostream>
using namespace std;

class Shape
{
 public:
    void draw()
    {
        cout<<"Drawing Shape:"<<endl;
    }
};
class Polygon:public Shape
{
    public:
       Polygon()
       {
        cout<<"Polygon created:"<<endl;
       }
       void draw_polygon()
       {
        cout<<"Drawing Polygon:"<<endl;
       }
};

class Rectangle:public Polygon
{
    public:
       Rectangle()
       {
        cout<<"Rectangle created:"<<endl;
       }
       void draw_rect()
       {
        cout<<"Drawing Rectangle:"<<endl;
       }
};

int main()
{
    Rectangle rect;

    rect.draw();
    rect.draw_polygon();
    rect.draw_rect();

    return 0;
}
