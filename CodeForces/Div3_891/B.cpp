#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int T;
  cin >> T;
 
  while (T--) {
    string str;
    cin >> str;
    str = '0'+str;
    int p = str.size();
 
    for (int a = str.size() - 1; a >= 0; a--) {
      if (str[a] >= '5')
        str[a - 1]++, p = a;
    }
 
    for (int a = (str[0] == '0'); a < str.size(); a++) {
      cout << (a >= p ? '0' : str[a]);
    }
    cout << "\n";
  }
}