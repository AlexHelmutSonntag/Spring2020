#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*C2 assignment
we know the distances of all settlements of Hungary from Kukutyin and from Piropocs
Write a program that gives the list of those settlements that are close than 100 km to Piropocs but are at least 100 Km away from Kukutyin
int main() {

Std input :-
6
42 15
110 20 
125 160
166 180
42 100
110 39

output :-
2 2 6

*/




int N;
cin>>N;
int KUKU[N];
int PIRI[N];
int count=0;
for (int i=0;i<N;i++)
{
    cin>>KUKU[i]>>PIRI[i];
}
vector<int> indices;
for (int i=0;i<N;i++)
{
    if(KUKU[i]>=100&&PIRI[i]<100)
      {  count++; 
    indices.push_back(i+1);
      }
}
cout<< count<<" ";
for (int i=0;i<count;i++)
{
    cout<<indices[i]<<" ";
}
cout<<endl;
}
