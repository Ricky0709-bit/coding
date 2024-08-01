#include<iostream>
using namespace std;

class dymc_arr
{
    private:
     int *arr;
     int size;
    
    public:
       dymc_arr(int size)
       {
           this->size=size;
           arr = new int[size];
       }
       ~dymc_arr()
       {
           delete []arr;
       }
       void init_arr()
       {
          cout<<"Enter:"<<size<<"integers:\n"<<endl;
          for(int i=0;i<size;++i)
          {
            cin>>arr[i];
          }
       }
       void display_arr()
       {
         cout<<"Array elements;\n"<<endl;
         for(int i=0;i<size;++i)
         {
            cout<<arr[i]<<" "<<endl;
         }
         cout<<endl;
     }
};

int main()
{
     int size;
     cout<<"Enter the size of the array:"<<endl;
     cin>>size;

     dymc_arr dymcarr(size);
     dymcarr.init_arr();
     dymcarr.display_arr();

     return 0;
}