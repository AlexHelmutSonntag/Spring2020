#include<iostream>
#include<string>

using namespace std;

int main(){

int numOfVowels =0;
string userString="";
cout << "enter a string " <<endl;

getLine(cin,userString);

for (int i=0;i<userString.length();i++)
{
if((userString[i] =='a') || (userString[i] =='e') || (userString[i] =='i') || (userString[i] =='o') || (userString[i] =='u'))
  numOfVowels = numOfVowels+1;
}

cout << numOfVowels<<endl;
return 0;
}
