#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; 
  long double area=0; 
  vector<double> h, w; 

  cin>>N; 
  h.resize(N+1); 
  w.resize(N); 
  for(int a=0; a<N+1; a++) cin>>h[a]; 
  for(int a=0; a<N; a++) cin>>w[a]; 

  for(int a=0; a<N; a++){
    area+=(h[a]+h[a+1])*w[a]/2; 
  }
  cout<<fixed<<setprecision(6)<<area<<endl;
}