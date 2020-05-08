#include<iostream>
#include<vector>
#include<string>


using namespace std;

struct temp
{   int Maxt;
    int Mint;
    
};

//Aly Elalwany WGL13Q

/*
input : 5
          30 25 5 
          25 20 5
          27 18 9
          30 20 10
          24 22 2
*/
int main()
{   
int N;
cin>> N;
temp Days[N];

for (int i=1;i<=N;i++)
{

    cin>> Days[i].Maxt >> Days[i].Mint;
}

int MinDif;
MinDif = Days[1].Maxt - Days[1].Mint;

int OutDays[N];
OutDays[1]=1;
int NCnt =1;
for(int i=2;i<=N;i++)
{
    if(Days[i].Maxt - Days[i].Mint==MinDif)
    {
        NCnt++;
        OutDays[NCnt]=i;
    }

    else if (Days[i].Maxt - Days[i].Mint < MinDif)
    {
        MinDif = Days[i].Maxt - Days[i].Mint;
        OutDays[1] = i;
        NCnt =1;
    }

}
cout<< NCnt<<endl;
for(int i=1;i<=NCnt;i++)
{
    cout<< OutDays[i]<<endl;
}

    return 0;
}
