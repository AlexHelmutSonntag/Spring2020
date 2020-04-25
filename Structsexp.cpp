#include<iostream>
#include<vector>

using namespace std;

//This file is about structures in C++  made on 25.04.2020

struct Car {

    string brand;
    int year, passengers;
    double consumption;
};

struct Employee{
    string name;
    int ID;
    string location;
};

struct segments{
        int points;
        int total;
        float percentage;
};

struct subject{
     string name;
     int marks;
     int credits;
     vector<segments> assessments; // a vector named assessments of type struct tag segments. so it has 3 elements from segments.
};

int main(){

vector<segments> assessments;//initializing a vector called assessments of type struct segments
assessments.push_back({1,3,0.33});// we assigned these elements to this element(also a vector) of type struct segments.
subject fach ={"English", 30, 5,assessments};

cout <<"subject\t marks \t credits " <<endl;
cout << fach.name<<"\t" <<fach.marks<<"\t" << fach.credits<<endl;



/*
int n; 
cin >> n;

Car cars[n];
for (int i=0;i<n;i++)
{  
       cin >> cars[i].brand >> cars[i].year >> cars[i].passengers;
}
cout <<"Brand\t Year \t Passengers" <<endl;
for (int i=0;i<n;i++)
{       
       cout << cars[i].brand <<"\t"<<cars[i].year << "\t"<<cars[i].passengers<<endl;
}
*/
Car Audi;
Audi.brand = "Audi";
Audi.year =1999;
Audi.passengers = 4;
//cout << Audi.passengers<<endl;//4
Audi.passengers++;
//cout << Audi.passengers<<endl;//5
//cout << Audi.year<<endl;//1999
Audi.year-=2;
//cout << Audi.year<<endl;//1997
Car myTruck = {"Volvo",2001,25};
//cout << myTruck.brand<<endl;//Volvo
myTruck.consumption = 20.5;

Car BMW={"BMW", 1986,4};

//Do the same with vectors reference to fix -> Stackoverflow 8067338

vector<Car> vec;

vec.push_back(Audi);//Almost as if you are creating a temporary object so that you could copy the vector to.

vec[0].brand = "Audi";
vec[0].year = 1992;//you can't initially input elements in vector this way it gives segmentation fault(core dump)
vec[0].passengers = 2;
vec.push_back(BMW);

vec.push_back({"Benz",1954,2});// this is the optimum way to do it 

/*
vec[1].brand = "BMW";
vec[1].year= 1986;
vec[1].passengers = 4;
*/
cout <<"Brand\t Year \t Passengers" <<endl;

for (int i=0; i<3;i++)
{
        cout << vec[i].brand <<"\t"<<vec[i].year << "\t"<<vec[i].passengers<<endl;
        /*Brand    Year    Passengers
        Audi       1997         5
        BMW        1986         4
        Benz       1954         2 */
}


vector<int> yearsOfCars;
yearsOfCars.push_back(Audi.year);
cout<< yearsOfCars[0]<<endl;//1997 because that's the only value stored in yearsOfCars because it is an int.

yearsOfCars.push_back(BMW.year);
cout<< yearsOfCars[1]<<endl;//1986 and this is how you add value in a vector.






return 0;
}
