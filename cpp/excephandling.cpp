#include <iostream>
using namespace std;

void checkPositive(int num) 
{
 if (num <= 0) 
 {
 throw runtime_error("Number is not positive.");
 }
}
int main()
{
 int number;
 cout << "Enter a positive number: ";
 cin >> number;
 try 
 {
 checkPositive(number);
 cout << "Number is positive." << endl;
 } 
 catch (const runtime_error& e) 
 {
 cout << "Exception caught: " << e.what() << endl;
 }
 return 0;
}