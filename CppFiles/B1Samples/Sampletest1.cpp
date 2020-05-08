#include<iostream>
#include<vector>
#include<string>


using namespace std;

// Aly Elalwany WGL13Q

/*Input : 5
          30 25
          25 20
          27 18
          30 20
          24 22
Output : 2
         5
         2




*/
struct temp{
            int Maxt;
            int Mint;
};
int main()
{
  int N;
  cin >> N;
  temp Days[N];
    for (int i=1;i<=N;i++)
{
    cin>>Days[i].Maxt >> Days[i].Mint;

}
int MaxDif = Days[1].Maxt - Days[1].Mint;
int NCnt=1;
int OutDays[N];
OutDays[1]= 1;
   for (int i=2;i<=N;i++)
{
    if((Days[i].Maxt - Days[i].Mint)== MaxDif)
    {
        NCnt++;
        OutDays[NCnt] = i;
    }


   else if((Days[i].Maxt-Days[i].Mint)> MaxDif)
    {

        OutDays[1] =i;
        MaxDif = Days[i].Maxt-Days[i].Mint;

    }
}
    cout<< NCnt<<endl;

    for(int i=1;i <=NCnt ;i++)
    {
        cout<<OutDays[i]<<endl;

    }



    return 0;
}
