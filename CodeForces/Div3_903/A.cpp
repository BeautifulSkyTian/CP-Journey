#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
 
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
 
    int ans = 0;
    while (x.size() < m) {
      x += x;
      ans++;
    }
    
    if (x == s) {
      cout << ans << endl;
      continue;
    }
 
    bool valid = 0;
    int a = 0;
    if(x.size()!=m){
      for (; a < x.size() - m; a++) {
        if (x.substr(a, m) == s) {
          cout << ans << endl;
          valid = 1;
          break;
        }
      }
    }
 
    if (!valid) {
      valid = 0;
      x += x;
      ans++;
      for (; a < x.size() - m; a++) {
        if (x.substr(a, m) == s) {
          cout << ans << endl;
          valid = 1;
          break;
        }
      }
      if (!valid)
        cout << -1 << endl;
    }
  }
}