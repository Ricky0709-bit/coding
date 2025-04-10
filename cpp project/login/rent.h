#include<iostream>
#include<fstream>
using namespace std;

class Vehicle
{
 public:
    string carnm,calcol,bodytype,fueltype,bname,bcolor,brakes;
    int carprice,carngn,bprice;
    float bngn,bmlg,carmlg;
    int v;

    void vmenu()
    { 
     cout<<"\n\t1.Bike \n\t2.Car \n\n\tPress 0 to Go Back \t\n"<<endl;
     cin>>v;
     if(v==1)
     {
      ifstream file("bike.txt");
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
            cout<<"\nERROR to display Bike Menu...\n"<<endl;
        }
     }
     if(v==2)
     {
      ifstream cfile("car.txt");
        if(cfile.is_open())
        {
          string cars;
          while (getline(cfile,cars))
          {
            cout<<cars<<endl;
          }
          cfile.close();
        }
        else
        {
            cout<<"\nERROR to display Car Menu...\n"<<endl;
        }
     }
     if(v==0)
     {
       vmenu();
     }
    }
    void Details(int x,int z)
    {
     if(v==1)
     {
          cout<<"\n\t\t             Select Your Bike :             \t\t\n"<<endl;   
          cin>>x;
          string bname;
          ifstream bfile1("bname.txt");  
    
          if(bfile1.is_open())
          {
          for(int i=0;i<x;i++)
          {
            bfile1>>bname;
          }
          bfile1.close();
          }
          else
          {
           cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }
          
          string bcolor;
          ifstream bfile2("bcolor.txt");  
    
          if(bfile2.is_open())
          {
              for(int i=0;i<x;i++)
              {
               bfile2>>bcolor;
              }
              bfile1.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          float bngn;
          ifstream bfile3("bngn.txt");  
    
          if(bfile3.is_open())
          {
              for(int i=0;i<x;i++)
              {
               bfile3>>bngn;
              }
              bfile3.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          float bmlg;
          ifstream bfile4("bmlg.txt");  
    
          if(bfile4.is_open())
          {
              for(int i=0;i<x;i++)
              {
               bfile4>>bmlg;
              }
              bfile4.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          string brakes;
          ifstream bfile5("brakes.txt");  
    
          if(bfile5.is_open())
          {
              for(int i=0;i<x;i++)
              {
               bfile5>>brakes;
              }
              bfile5.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          int bprice;
          ifstream bfile6("bprice.txt");  
    
          if(bfile6.is_open())
          {
              for(int i=0;i<x;i++)
              {
               bfile6>>bprice;
              }
              system("ClS");
              cout<<"\n                   Bike Details:               \n"<<endl;
              cout<<"\n\tBike Name :"<<bname<<endl;
              cout<<"\tColor :"<<bcolor<<endl;
              cout<<"\tEngine :"<<bngn<<" cc"<<endl;
              cout<<"\tMileage :"<<bmlg<<" kmpl"<<endl;
              cout<<"\tBrakes :"<<brakes<<endl;
              cout<<"\tPrice : Rs."<<bprice<<endl;
              bfile6.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }
         }   
      if(v==2)
        {
          cout<<"\n\t\t             Select Your Car :             \t\t\n"<<endl;   
          cin>>z;
          string carnm;
          ifstream cfile1("carnm.txt");  
    
          if(cfile1.is_open())
          {
          for(int i=0;i<z;i++)
          {
            cfile1>>carnm;
          }
          cfile1.close();
          }
          else
          {
           cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }
          
          string carcol;
          ifstream cfile2("carcol.txt");  
    
          if(cfile2.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile2>>carcol;
              }
              cfile2.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          float carngn;
          ifstream cfile3("carngn.txt");  
    
          if(cfile3.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile3>>carngn;
              }
              cfile3.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          float carmlg;
          ifstream cfile4("carmlg.txt");  
    
          if(cfile4.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile4>>carmlg;
              }
              cfile4.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          string bodytype;
          ifstream cfile5("bodytype.txt");  
    
          if(cfile5.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile5>>bodytype;
              }
              cfile5.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          string fueltype;
          ifstream cfile6("fueltype.txt");  
    
          if(cfile6.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile6>>fueltype;
              }
              cfile6.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }

          int carprice;
          ifstream cfile7("carprice.txt");  
    
          if(cfile7.is_open())
          {
              for(int i=0;i<z;i++)
              {
               cfile7>>carprice;
              }
              system("ClS");
              cout<<"\n                  Car Details:                \n"<<endl;
              cout<<"\n\tCar Name :"<<carnm<<endl;
              cout<<"\tColor :"<<carcol<<endl;
              cout<<"\tEngine :"<<carngn<<" cc"<<endl;
              cout<<"\tMileage :"<<carmlg<<" kmpl"<<endl;
              cout<<"\tBody Type :"<<bodytype<<endl;
              cout<<"\tFuel Type :"<<fueltype<<endl;
              cout<<"\tPrice : Rs."<<carprice<<endl;
              cfile7.close();
          }
          else
          {
             cout<<"\n ERROR Please Try Again...!\n"<<endl;
          }
         }  
    }
};




 


