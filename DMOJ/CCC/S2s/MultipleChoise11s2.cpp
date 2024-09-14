#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ac=0; 
  string answer; 

  cin>>N; 
  answer.resize(2*N, ' '); 
  for(int a=0; a<2*N; a++) cin>>answer[a]; 

  for(int a=0; a<N; a++){
    if(answer[a]==answer[N+a]) ac++; 
  }
  cout<<ac<<endl; 
}