#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Months 12 // you could define the size of the array here globally. But the array can't add then elements.
#define Years 5 
int length(char str[]){

int i=0;

for (i= 0; str[i] !='\0';i++);

return i;}

int gcd (int x ,int y )
{
    int result =0;
    
    for (int i=1;i<=x || i<=y ;i++)
       if (x%i==0 && y%i==0)
            result=i;

return result;
}

float abs_value(float var){

  float returnvalue=0;

    if(var<0)
    returnvalue= -var;

    else if (var>0)
    returnvalue = var;

return returnvalue;
}

float square_root(float number){

float returnvalue=0;
const float epsilon = .00001;
float guess =1.0;
 if (number<0)
    {  printf("-1\n");
        returnvalue = -1;
    }
if(returnvalue!=-1.0)
while(abs(guess*guess-number)>=epsilon )
    {
        guess = (number/guess+guess)/2.0;
        returnvalue = guess;
    }

return returnvalue;
}



int main(){

int result = gcd(10,5);
printf("%d\n",result);

result = gcd(150,35);
printf("%d\n",result);

result = gcd(1026,405);
printf("%d\n",result);

result = gcd(83,240);
printf("%d\n",result);


float abs = abs_value(-21.0);
printf("%.3f\n",abs);

abs = abs_value(-1876.879);
printf("%.3f\n",abs);

float sqrt = square_root(-1);
printf("%.2f\n",sqrt);

sqrt = square_root(25);
printf("%.2f\n",sqrt);
sqrt = square_root(16);
printf("%.2f\n",sqrt);

sqrt = square_root(225);
printf("%.2f\n",sqrt);
















/*
printf("%d\n",length("apple now"));
printf("%d\n",strlen("applenow"));
*/
/*
int Array[10]={1,2,3,4,5,6,7,8,9};
int *p = Array; // they both point to the same element in the array. but when *p=Array; without index, that means point to this array, but I don't know which element? then point to the first.
int *pr = &Array[0];// this points to the address of the first element in the array that's why we had to put & .
// int *p =arr;    //same function
//int p = &arr[0]; //same function
int *pr4 = &Array[3];
*/
/*printf("%p\n",p);
printf("%p\n",pr);
printf("%d\n",*pr4);
printf("%p\n",pr4);
printf("%p\n",(pr+3));
*/


/*
int Matrix[3][3]= {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

*/
/*
int Primes[50];
int primeIndex=2;
Primes[0]=2;
Primes[1]=3;
int p;
int i;
bool isPrime;
for(int p=5;p<=100;p+=2)
{   isPrime = true;
        for (int i=1;isPrime && (p/Primes[i])>=Primes[i];i++)
        { if (p % Primes[i]==0)
                    isPrime = false;
            
                if(isPrime==true)
            {
                Primes[primeIndex]=p;
                    ++primeIndex;
            }
        }
            
            
    }

for (int i=0;i<primeIndex;i++)
    {
            printf("%d\n",Primes[i]);
    }



*/

/*

//total rainfall for each year.
//yearly average rainfall = total /5 
//average rainfall for each month
float rain[Years][Months]={
                    {4.3,4.3,4.3,3.0,3.0,0.2,1.2,0.4,3.5,3.5,2.6,6.6},
                    {3.0,3.0,4.3,2.1,1.3,0.2,3.5,3.8,2.2,3.0,6.6,3.0},
                    {1.2,3.4,5.4,2.3,5.6,4.3,3.4,4.3,3.4,4.3,0.2,6.5},
                    {2.5,6.6,3.5,2.4,1.5,6.9,3.5,2.2,2.3,4.1,2.1,2.4},
                    {2.3,6.3,5.2,4.3,3.9,5.9,4.6,7.5,5.2,2.3,2.2,4.1}
};

float temp;
float sum=0.0,totalYears, sumYear=0.0;
printf("Year\tRainfall (inches)\n");
for (int year=0;year<Years;year++)
{   
    for (int month=0,sumYear=0.0;month<Months;month++)
    {    sumYear+=rain[year][month];
        temp = sumYear;
        printf("Average throughout month #%d : %f\n",month+1,sumYear/12.0);
        totalYears+=sumYear;
    }
        printf("Total from 2010 until  %d : %f\n",2010+year,totalYears);
        
}
printf("Yearly average is %f\n",totalYears/Years);
*/

return 0;
}
