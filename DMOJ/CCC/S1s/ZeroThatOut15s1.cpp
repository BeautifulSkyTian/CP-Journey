#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  int user=0;
  int sum=0;
  vector<int> input;

  for(int a=0; a<N; a++){
    cin>>user;
    if(user==0) input.resize(input.size()-1);
    else input.push_back(user);
  }

  for(int a: input) sum+=a;
  cout<<sum<<endl;
}