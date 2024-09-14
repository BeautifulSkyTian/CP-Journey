#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; 
  vector <double> d; 
  vector <double> size;

  cin>>N; 

  d.resize(N);
  for(int a=0; a<N; a++) cin>>d[a]; 
  sort(d.begin(), d.end());

  for(int a=1; a<N-1; a++){
    size.push_back((d[a+1]+d[a])/2 - (d[a-1]+d[a])/2); 
  }

  sort(size.begin(), size.end()); 
  cout<<fixed<<setprecision(1)<<size[0];
}