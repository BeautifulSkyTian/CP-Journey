#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> x;

  if (x < 4)
    cout << '0' << endl;
  else {
    int ans = 0;
    for (int a = 1; a <= x - 3; a++) {
      for(int b=a+1; b<=x-2; b++){
          for(int c=b+1; c<=x-1; c++){
              ans++; 
          }
      }
    }
    cout << ans << endl;
  } //1, 2, 3, 4, 5, 6, 7, 8, 9, 10
}