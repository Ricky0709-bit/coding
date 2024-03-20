#include<iostream>
using namespace std;

class Vehicle
{
  protected:
     float mileage;
     float price;
  public:
     void vehd()
     {
        cout<<"Enter the mileage of the vehicle : ";
        cin>>mileage;
        cout<<"Enter the price of the vehicle : ";
        cin>>price;
     }  
};

class Car : virtual public Vehicle
{
    protected:
       float own_cost;
       float warranty;
       int seat_capacity;
       string fueltype;
    public:
       void  carDetails()
       {
        cout<<"Enter Ownership Cost: ";
        cin>>own_cost;
        cout<<"Enter Warranty period : ";
        cin>>warranty;
        cout<<"Enter Seat Capacity:";
        cin>>seat_capacity;
        cout<<"Enter Fuel Type:"<<endl<<"1. Petrol\n2. Diesel\n3. CNG:\t";
        int f;
        cin>>f;
        if(f==1)
        {
            fueltype="Petrol";
        }
        else if (f==2)
        {
            fueltype="Diesel";
        }
        else
        {
            fueltype="CNG";
        }
       }
};

class Bike : virtual public Vehicle
{
    protected:
       int nocyl;
       int nogear;
       string cooltype;
       string wheeltype;
       float ftanksize;
    public:
       void bikeDetails()
       {
        cout<<"Enter No. of cylinders: ";
        cin>>nocyl;
        cout<<"Enter No. of Gears: ";
        cin>>nogear;
        cout<<"\nEnter Cooling type:\n1. Air\n2. Liquid \n3.Oil:\t";
        int c;
        cin>>c;
        if(c==1)
        {
            cooltype="Air";
        }
        else if (c==2)
        {
            cooltype="Liquid";
        }
        else
        {
            cooltype="Oil";
        }
        cout<<"Enter Wheel Type:\n1. Alloy Wheels\n2. Spoked Wheels:\t";
        int w;
        cin>>w;
        if(w==1)
        {
            wheeltype="Alloy Wheels";
        }
        else
        {
            wheeltype="Spoked Wheels";
        }
        cout<<"Enter Fuel Tank Size : ";
        cin>>ftanksize;
       }
};

class Audi:public Car
{
    private:
       string modeltype;
    public:
       void gaudi()
       {
        cout<<"\nEnter Model Type of Audi : ";
        cin>>modeltype;
       }
       void  showcar()
       {
        gaudi();
        vehd();
        Car::carDetails();
        cout<<"__________________________________________________________"<<endl;
        cout<<"\nModel Type of Audi: "<<modeltype<<endl;
        cout<<"Mileage:"<<mileage<<" KM/L"<<endl;
        cout<<"Price: Rs."<<price<<" Lakh"<<endl;
        cout<<"Ownership cost: Rs."<<own_cost<<" Lakh"<<endl;
        cout<<"Warranty:"<<warranty<<" Yrs"<<endl;
        cout<<"Seat capacity:"<<seat_capacity<<endl;
        cout<<"Fuel type:"<<fueltype<<endl;
       }
       
};

class Ford:public Car
{
    private:
       string modeltype;
    public:
       void gford()
       {
        cout<<"\nEnter Model Type of Ford :"<<endl;
        cin>>modeltype;
       }
       void showcar()
       {
        cout<<"_______________________________________________________________"<<endl;
        gford();
        vehd();
        Car::carDetails();
        cout<<"_______________________________________________________________"<<endl;
        cout<<"\nModel Type of Ford: "<<modeltype<<endl;
        cout<<"Mileage:"<<mileage<<" KM/L"<<endl;
        cout<<"Price: Rs."<<price<<" Lakh"<<endl;
        cout<<"Ownership cost: Rs."<<own_cost<<" Lakh"<<endl;
        cout<<"Warranty:"<<warranty<<" Yrs"<<endl;
        cout<<"Seat capacity:"<<seat_capacity<<endl;
        cout<<"Fuel type:"<<fueltype<<endl;
       }
};

class TVS:public  Bike
{
    private:
       string maketype;
    public:
       void gtvs()
       {
        cout<<"Enter Make Type of TVS :"<<endl;
        cin>>maketype;
       }
       void  showbike()
       {
        cout<<"__________________________________________________________________"<<endl;
        gtvs();
        vehd();
        Bike::bikeDetails();
        cout<<"__________________________________________________________________"<<endl;
        cout<<"\nMake Type of TVS:"<<maketype<<endl;
        cout<<"Mileage:"<<mileage<<" KM/L"<<endl;
        cout<<"Price: Rs."<<price<<" Lakh"<<endl;
        cout<<"No. of cylinders:"<<nocyl<<endl;
        cout<<"No. of  Gears:"<<nogear<<endl;
        cout<<"Cooling Type:"<<cooltype<<endl;
        cout<<"Wheel Type:"<<wheeltype<<endl;
        cout<<"Fuel Tank Size:"<<ftanksize<<" Inches"<<endl;
       }
};

class Bajaj:public Bike
{
    private:
       string maketype;
    public:
       void  gbajaj()
       {
        cout<<"Enter Make Type of Bajaj :"<<endl;
        cin>>maketype;
       }
       void showBike()
       {
        cout<<"__________________________________________________________________"<<endl;
        gbajaj();
        vehd();
        Bike::bikeDetails();
        cout<<"__________________________________________________________________"<<endl;
        cout<<"\nMake Type of Bajaj:"<<maketype<<endl;
        cout<<"Mileage:"<<mileage<<" KM/L"<<endl;
        cout<<"Price: Rs."<<price<<" Lakh"<<endl;
        cout<<"No. of cylinders:"<<nocyl<<endl;
        cout<<"No. of  Gears:"<<nogear<<endl;
        cout<<"Cooling Type:"<<cooltype<<endl;
        cout<<"Wheel Type:"<<wheeltype<<endl;
        cout<<"Fuel Tank Size:"<<ftanksize<<" Inches"<<endl;
       }    
};

int main()
{
    Audi a;
    Ford f;
    TVS t;
    Bajaj b;

    a.showcar();
    f.showcar();
    t.showbike();
    b.showBike();

    return 0;
}
 
