#include <iostream>
#include <vector>
using namespace std;


// This code outputs the longest only-digit string.
int main() {
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }
  
  string code = "";
  for (int i = 0; i < n; i++) {
    bool number = true;
    for (int j = 0; j < words[i].length(); j++) {
      if (words[i][j] < '0' || words[i][j] > '9') number = false;
    }
    if (number && words[i].length() > code.length()) {
      code = words[i];
    }
  }
  cout << code << endl;
}
