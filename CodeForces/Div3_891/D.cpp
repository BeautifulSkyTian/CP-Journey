#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(0); 
  cin.tie(0); 
 
  int T; cin>>T; 
 
  while(T--){
    int n; cin>>n; 
 
    vector<int> A(n), B(n); 
 
    for(int a=0; a<n; a++) cin>>A[a]; 
    for(int a=0; a<n; a++) cin>>B[a]; 
 
    vector<int> C(n); 
    int mx=INT_MIN; 
    for(int a=0; a<n; a++){
      C[a]=A[a]-B[a]; 
      mx=max(mx, C[a]); 
    }
 
    int ans=0; 
    vector<int> ar; 
    for(int a=0; a<n; a++){
      if(C[a]==mx) {
        ans++; 
        ar.push_back(a+1); 
      }
    }
    cout<<ans<<endl; 
    for(int a=0; a<ar.size(); a++) cout<<ar[a]<<" "; 
    cout<<"\n"; 
  }
}