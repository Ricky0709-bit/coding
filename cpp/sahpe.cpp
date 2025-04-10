#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Base class
class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const {
        return length * width;
    }
};

int main() {
    const int MAX_SHAPES = 100;
    Shape* shapes[MAX_SHAPES];
    int shapeCount = 0;

    ifstream inputFile("shapes.txt");
    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string shapeType;
    while (inputFile >> shapeType) {
        if (shapeType == "Circle") {
            double radius;
            inputFile >> radius;
            shapes[shapeCount++] = new Circle(radius);
        } else if (shapeType == "Rectangle") {
            double length, width;
            inputFile >> length >> width;
            shapes[shapeCount++] = new Rectangle(length, width);
        }
    }

    inputFile.close();

    double totalArea = 0.0;
    for (int i = 0; i < shapeCount; ++i) {
        totalArea += shapes[i]->area();
    }

    cout << "Total area of all shapes: " << totalArea << endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }

    return 0;
}
