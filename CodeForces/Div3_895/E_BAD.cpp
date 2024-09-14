#include <bits/stdc++.h>
using namespace std; 
 
int main(){
  cin.sync_with_stdio(0); 
  cin.tie(0); 
 
  int T; cin>>T; 
  while(T--){
    int N; cin>>N; 
    vector<int> ar(N+1); 
    for(int a=1; a<=N; a++) cin>>ar[a];
    
    int perm0=0, perm1=0; 
    for(int a=1; a<=N; a++){
      char x; cin>>x; 
      int y=x-48; 
      if(!y) perm0=perm0^ar[a]; 
      else perm1=perm1^ar[a]; 
    }
    
    int Q; cin>>Q; 
    for(int i=0; i<Q; i++){
      int x; cin>>x; 
 
      if(x==2){
        int y; cin>>y; 
        if(y==0) cout<<perm0<<" "; 
        else cout<<perm1<<" "; 
      }
      else{
        int l, r; cin>>l>>r; 
        for(int a=l; a<=r; a++){
          perm0=perm0^ar[a]; 
          perm1=perm1^ar[a];
        }
      }
    }
 
    cout<<"\n"; 
  }
}
/*
a[12, 12, 14, 14, 5, 5]
pref[0, 1, 2, 3, 4, 5]
pref[]
*/