#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N; 
  int ans=1; 
  vector<string> group1(N), group2(N); 
  map<string, string> group; 

  for(int a=0; a<N; a++) cin>>group1[a]; 
  for(int a=0; a<N; a++) cin>>group2[a]; 
  for(int a=0; a<N; a++) group[group1[a]]=group2[a]; 
  
 // for(pair<string, string> a:group) cout<<a.first<<" "<<a.second<<endl;
  for(pair<string, string> a: group){
    if(a.first!=group[a.second] || a.first==a.second){
      ans=0; 
      break;
    }
  }
  if(ans) cout<<"good"<<endl;
  else cout<<"bad"<<endl;
}