
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
 
  int T; cin>>T; 
  while(T--){
    int n; cin>>n; 

    int ans=INT_MAX; 
    for(int a=0; a<n; a++){
        int x, y; cin>>x>>y; 

        ans=min(ans, x+(y-1)/2); 
    }

    cout<<ans<<endl; 
  }
}