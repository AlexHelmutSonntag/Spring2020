#include <iostream>
using namespace std;

//Make a program that gives the day on which the diff between the expected minimum and expected maximum is the smallest
/*
Standard input :-   output should be 3
6
-5 5
0 10 
-5 -3 
-5 0
2 10
10 13
*/

int main(){

int n, i;
 cin >> n;
int Min[n], Max[n], Diff[n];
 
 
for ( i =1;i<=n;i++)
{
    cin >> Min[i];
    cin >> Max[i];
}
// -5 0 -5 -5 2 10 
// 5 10 -3 0 10 13 

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
return 0;
}
