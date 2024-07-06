#include <iostream>
using namespace std;

class Date 
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }
    Date(int d, int m, int y) 
    {
        day = d;
        month = m;
        year = y;
    }
    void displayDate() 
    {
      cout << "Date: " << day << "-" << month << "-" << year << endl;
    }
};

int main() 
{
    Date defaultDate;
    cout << "Default Date: ";
    defaultDate.displayDate();

    Date customDate(3, 3, 2024);
    cout << "Custom Date: ";
    customDate.displayDate();

    return 0;
}
