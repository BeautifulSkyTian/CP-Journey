#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, quest, ans=0; 
  cin>>quest>>N; 
  vector<int> Dmo(N),Peg(N); 

  for(int a=0; a<N; a++) cin>>Dmo[a]; 
  for(int a=0; a<N; a++) cin>>Peg[a]; 

  if(quest==2){
    sort(Dmo.begin(), Dmo.end(), greater<int>()); 
    sort(Peg.begin(), Peg.end()); 
    for(int a=0; a<N; a++) ans+=max(Dmo[a], Peg[a]); 
  }
  else{
    sort(Dmo.begin(), Dmo.end()); 
    sort(Peg.begin(), Peg.end()); 
    for(int a=0; a<N; a++) ans+=max(Dmo[a], Peg[a]); 
  }
  cout<<ans<<endl; 
}