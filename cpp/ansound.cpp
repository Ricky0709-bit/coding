#include <iostream>

using namespace std;

// Base class
class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() {
        cout << "Woof Woof" << endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() {
        cout << "Meow Meow" << endl;
    }
};

// Derived class Cow
class Cow : public Animal {
public:
    void makeSound() {
        cout << "Moo Moo" << endl;
    }
};

int main() {
    // Array of Animal pointers
    Animal* animals[3];

    // Creating objects of derived classes and storing their pointers in the array
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    // Iterating over the array and calling makeSound() for each element
    for (int i = 0; i < 3; ++i) {
        animals[i]->makeSound();
    }

    // Cleaning up dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }

    return 0;
}
