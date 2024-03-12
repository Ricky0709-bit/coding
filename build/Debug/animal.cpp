#include <iostream>
using namespace std;


class Animal {
public:
    
    virtual void sound() = 0;
};


class Dog : public Animal 
{
public:
    
    void sound()
    {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};


class Cat : public Animal 
{
public:
    
    void sound()
   {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

int main() {
    
    Dog dog;
    Cat cat;

    
    cout << "Sound of Dog: ";
    dog.sound();

    cout << "Sound of Cat: ";
    cat.sound();

    return 0;
}
