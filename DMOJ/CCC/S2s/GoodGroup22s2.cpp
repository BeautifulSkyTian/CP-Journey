#include <bits/stdc++.h>
using namespace std;

int main(){
  int M, N; cin>>M>>N; 
  int K; cin>>K; 

  vector<int> R(M+1), C(N+1); 
  for(int a=0; a<K; a++){
    char x; int y; 
    cin>>x>>y; 
    if(x=='R') R[y]=!R[y]; 
    else C[y]=!C[y]; 
  }

  int x=0, y=0; 
  for(int a=1; a<M+1; a++) if(R[a]) x++; 
  for(int a=1; a<N+1; a++) if(C[a]) y++; 

  int ans=x*N+y*M-2*x*y; 
  cout<<ans<<endl; 

  
}