#include <iostream>
using namespace std;


class Counter 
{
private:
    static int count;

public:
   
    static void increment() {
        count++;
    }

    
    static int getCount() {
        return count;
    }
};


int Counter::count = 0;

int main() {
   
    Counter::increment();
    Counter::increment();
    Counter::increment();

    
    cout << "Value of count: " << Counter::getCount() << endl;

    
    Counter::increment();

    
    cout << "Updated value of count: " << Counter::getCount() << endl;

    return 0;
}
