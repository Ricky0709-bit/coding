#include<iostream>
#include<fstream>
using namespace std;

class BookTrip
{
 public:

    string p_l;
    string d_l;
    float distance,cost;


    void data()
    {
     cout<<"\n                 Enter Trip Information:                     \n"<<endl;
   
     cout << "Pick Up Location : "<<endl;
     cin>>p_l;
     cout<<"Drop Off Location : "<<endl;
     cin>>d_l;
     cout<<"Distance (in KM):"<< endl;
     cin>>distance;
    }

   void menu()
    {
        ifstream file("rides.txt");
        if(file.is_open())
        {
          string line;
          while (getline(file,line))
          {
            cout<<line<<endl;
          }
          file.close();
        }
        else
        {
            cout<<"\nERROR to display Menu...\n"<<endl;
        }
}

    void Details(int ch)
    {
     cout<<"\n\t\t             Select Your Ride :             \t\t\n"<<endl;   
     cin>>ch;
     string model;
     ifstream file1("model.txt");  
    
     if(file1.is_open())
     {
         for(int i=0;i<ch;i++)
         {
            file1>>model;
         }
         file1.close();
     }
     else
     {
        cout<<"\n ERROR Please Try Again...!\n"<<endl;
     }
     
     int seat;
     ifstream file2("seat.txt");  
    
     if(file2.is_open())
     {
         for(int i=0;i<ch;i++)
         {
            file2>>seat;
         }
         file2.close();
     }
     else
     {
        cout<<"\n ERROR Please Try Again...!\n"<<endl;
     }

     float price_perkm;
     ifstream file3("price.txt");
     if(file3.is_open())
     {
         for(int i=0;i<ch;i++)
         {
            file3>>price_perkm;
         }
        system("ClS");
        cout<<"\n                  Trip Details                 \n";
        cout<<"\n\tPick Up Location :"<<p_l<<endl;
        cout<<"\tDrop Off Location :"<<d_l<<endl;
        cout<<"\tDistance :"<<distance<<" KM"<<endl;
        cout<<"\tVehicle :"<<model<<endl;
        cout<<"\tSeats :"<< seat<<endl;
        cout<<"\tPrice(/KM) : Rs."<<price_perkm<<endl;
        cost=distance* price_perkm;
        cout<<"\tTotal Cost : Rs."<<cost<<endl;
         file1.close();
     }
     else
     {
        cout<<"\n ERROR Please Try Again...!\n"<<endl;
     }
    }
    

};
