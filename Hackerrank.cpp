#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;


void(update(int *anyname,int *anyname2))//these two variables are pointers of values equal to the pointers in int main.
{
        *anyname+= *anyname2;    
        *anyname2= abs(*anyname-2**anyname2);

}

int main(){

int n,q;
cin >> n >> q;
vector< vector<int> > a(n);

// input each array
for (int i=0;i<n;i++) {
    int k;
    cin >> k;

    for (int j=0;j<k;j++) {
        int data;
        cin >> data;
        a[i].push_back(data);
    }
}

// do the queries
for (int i=0;i<q;i++) {
    int x,y;
    cin >> x >> y;
    cout << a[x][y] << endl;
}

/*
int a,b;
int *pa=&a, *pb =&b;

cin>>a>>b;
update(pa,pb);//you give in the values of these pointers to the function as arguments.
cout<<a<<endl;
cout<<b<<endl;
*/
 return 0;
}
