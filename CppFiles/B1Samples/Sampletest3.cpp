#include<iostream>

using namespace std;

struct Car{
            float fuel;
            float consump;
};

int main(){

int Count;
cin >> Count;
int Count80=0;
bool ExistEmpty = false;
int CarsInd[Count];
Car Cars[Count];

for(int i=0;i<Count;i++)
{
    cin>>Cars[i].fuel>>Cars[i].consump;
}

for(int i=0;i<Count;i++)
{
    if(Cars[i].consump*0.8<=Cars[i].fuel)
    {
        Count80=Count80+1;
        CarsInd[Count80-1]=i+1;
    }
}
cout <<Count80<<endl;
for(int i=0;i<Count80;i++)
{
    cout<<CarsInd[i]<<endl;
}

int i=0;
while(i<Count&&Cars[i].fuel !=40.0)
{
    i++;
}
ExistEmpty = (i<Count);

cout<<ExistEmpty<<endl;


return 0;
}
