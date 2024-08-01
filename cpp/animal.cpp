#include <iostream>

using namespace std;

// Base class
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() {
        cout << "Dog barks" << endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() {
        cout << "Cat meows" << endl;
    }
};

// Derived class Cow
class Cow : public Animal {
public:
    void makeSound() {
        cout << "Cow moos" << endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;
    Cat cat;
    Cow cow;

    // Using base class pointer to refer to derived class objects
    animalPtr = &dog;
    animalPtr->makeSound();  // Output: Dog barks

    animalPtr = &cat;
    animalPtr->makeSound();  // Output: Cat meows

    animalPtr = &cow;
    animalPtr->makeSound();  // Output: Cow moos

    return 0;
}
