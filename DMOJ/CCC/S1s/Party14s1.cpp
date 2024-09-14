#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, M;
  bool valid=true;
  vector<int> R, remain1, remain2;

  cin>>K>>M;
  R.resize(M);
 // cout<<R.size()<<endl;
  for(int a=0; a<M; a++) cin>>R[a];
  //for(int a: R) cout<<a<<" ";

  for(int a=1; a<=K; a++) remain1.push_back(a);
  for(int a: R){
    for(int b=0; b<remain1.size(); b++){
      if((b+1)%a!=0) remain2.push_back(remain1[b]); 
    }
    remain1=remain2;
    remain2.resize(0);
  }
  for(auto a: remain1) cout<<a<<endl;
}