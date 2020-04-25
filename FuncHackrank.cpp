#include<iostream>
#include<vector>

using namespace std;

int sum_of_four (int a,int b ,int c,int d){

int sum=0;
sum+= a;
sum+= b;
sum+= c;
sum+= d;
        return sum;
}


int max_of_four(int a,int b,int c,int d){


int Num[]={a,b,c,d};
int max = 0;
int ans;

for (int i=1;i<4;++i)
{
            if (Num[max]>Num[i])
               { 
                   ans=Num[max];
               }            
            else 
                {   max=i;
                    ans=Num[max];                            
                }
}
cout <<ans<<endl;
    return ans;
}
int main(){

/*
int a,b,c,d;
cin>>a>>b>>c>>d;
int ans = max_of_four(a,b,c,d);
*/


/*
int a,b,c,d;

cin>> a >>b >>c >>d;

int sum = sum_of_four(a,b,c,d);

cout <<sum<<endl;
*/
//Solution to a for loop question on Hackerrank


/*
int a,b;
string c[]={"","one","two","three","four","five","six","seven","eight","nine"};
cin >> a>>b;

for (int i=a;i<=b;i++)
{   
          cout<<( (i<=9)?c[i] : ((i%2==0)?"even":"odd") )<<endl;
}
*/

return 0 ;
}
