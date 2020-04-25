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
int ans = Num[0];


for (int i=1;i<4;++i)
{
            if (Num[i]>Num[i-1])
                 ans = Num[i];
}
    return ans;
}
int main(){
/*
int a,b,c,d;
cin>>a>>b>>c>>d;
int ans = max_of_four(a,b,c,d);
cout <<ans<<endl;
*/

/*
int a,b,c,d;

cin>> a >>b >>c >>d;

int sum = sum_of_four(a,b,c,d);

cout <<sum<<endl;
*/



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
