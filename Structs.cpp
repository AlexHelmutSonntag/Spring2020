#include <iostream>
#include <vector>
using namespace std;

struct Car {
  string brand;
  int year, passengers;
  double consumption;
};

int main() {
	cout << "Good morning everyone! We are learning about structs in C++.";
  int n;
  cin >> n;
  
  /* Simple, bit ugly solution
  string brand[n];
  int year[n], passengers[n];
  for (int i = 0; i < n; i++) {
    cin >> brand[i] >> year[i] >> passengers[i];
  }*/
  
  // Something much better
  Car cars[n];
  for (int i = 0; i < n; i++) {
    cin >> cars[i].brand >> cars[i].year >> cars[i].passengers;
  }
  for (int i = 0; i < n; i++) {
    cout << "brand: " << cars[i].brand << ", year: " << cars[i].year
         << ", passengers: " << cars[i].passengers << endl;
  }
  
  int whatever = 5;
  
  Car myCar; // Type variable_name;
  myCar.brand = "Audi"; // variable_name.member = value;
  myCar.year = 2000;
  myCar.passengers = 5;
  myCar.passengers++;
  myCar.year -= 2;
  cout << "brand: " << myCar.brand << ", year: " << myCar.year
         << ", passengers: " << myCar.passengers << endl;
         
  Car myTruck{"Volvo", 2001, 25};
  myTruck.consumption = 20.5;
  cout << "brand: " << myTruck.brand << ", year: " << myTruck.year
         << ", passengers: " << myTruck.passengers
         << ", consumption: " << myTruck.consumption  << endl;
         
  vector<Car> vec;
  vec.push_back(myCar);
  vec.push_back(myTruck);
  
  vector<int> yearsOfCars;
  yearsOfCars.push_back(myCar.year);
	return 0;
}
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

struct person {
  string name;
  int crimes;
};

int main() {
  // Write your program here.
  int n;
  cin >> n;
  person p[n];
  for (int i = 0; i < n; i++) {
      cin >> p[i].name >> p[i].crimes;
  }
  
  vector<person> list;
  for (int i = 0; i < n; i++) {
      if (p[i].crimes >= 3) {
          list.push_back(p[i]);
      }
  }
  
  cout << list.size() << endl;
  for (int i = 0; i < list.size(); i++) {
      cout << list[i].name << endl;
  }
}
// Doing an old task with structs.
#include <iostream>
#include <vector>
using namespace std;

struct Rachel{
  
 int arrival;
 int departure;
};
int main()
{
  int n,x;
  cin >> n;
  Rachel guests[n];
 cin >> x; 
  for(int i=0; i<n;i++)
{
  cin >> guests[i].arrival>>guests[i].departure;
  
}
 int counter =0;
  vector<Rachel> present;
   for(int i=0; i<n;i++)
{
  if (guests[i].arrival<=x && guests[i].departure >= x)
    {
    counter++;
    }
 }
 cout << counter;
return 0;
}

#include <iostream>
using namespace std;

struct Date {
  int month, day;
};

int main() {
	int n;
    cin >> n;
    Date birth[n + 1];
    
    for (int i = 1; i <= n; i++) {
        cin >> birth[i].month >> birth[i].day;
    }
    
    int first = 1;
    for (int i = 2; i <= n; i++) {
        if (birth[i].month < birth[first].month ||
            birth[i].month == birth[first].month
            && birth[i].day < birth[first].day) {
            first = i;
        }
    }
    cout << "First birthday in year: " << birth[first].month
         << " " << birth[first].day << ", person " << first;
    return 0;
}
