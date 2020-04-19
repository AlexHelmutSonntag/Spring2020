#include <iostream>
using namespace std;

int main(){


/*
# C1 Programming assignment
Make a program that takes the minimum expected temperature and the highest expected temperature and display the index of
the day on which the difference between the expected minimum expected maximum  is the smallest.
*/

int n, i;
 cin >> n;
 // 6
int Min[n], Max[n], Diff[n];
 
 
for ( i =1;i<=n;i++)
{
    cin >> Min[i];
    cin >> Max[i];
}
// -5 5 0 10 -5 -3 -5 0 2 10 10 13 

 /*
for ( i =1;i<=n;i++)
{
     cin >> Max[i];
}
*/
for ( i =1;i<=n;i++)
{
    Diff[i] = Max[i] - Min[i];
        
}

int miniindex = 1;
//10 3 2 5 8 3
for (i=2;i<n;i++)
{
    if(Diff[miniindex]>Diff[i])
    {
        miniindex = i;   
    }


}

cout<< miniindex<<endl;

// 3





return 0;
}
