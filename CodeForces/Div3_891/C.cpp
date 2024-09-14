#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
 
    int m = n * (n - 1) / 2;
    vector<int> ar(m, 0);
 
    for (int a = 0; a < m; a++)
      cin >> ar[a];
    sort(ar.begin(), ar.end());
 
    int itr = 0;
    for (int a = 1; a < n; a++) { // The reason why you do not use a<=n is because a is the starting position in array A for figuring out min values. Since a_i < a_j, a technically should not reach n which is the last element in 
    // array A. If we were to put a<=n, then itr would eventually add 0 to itself which causes the same value to be printed twice. That is why our previous submissions were wrong. This is why a should be smaller than n. 
      itr += n - a;
      cout << ar[itr - 1] << " ";
    }
    cout << 1000000000 << "\n";
  }
}