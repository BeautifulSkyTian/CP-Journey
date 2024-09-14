#include <bits/stdc++.h>
using namespace std;

int size(char a){
  if(a=='L') return 3; 
  else if(a=='M') return 2; 
  else return 1; 
}

int main() {
  int J, A, ans=0; 
  cin>>J>>A; 
  vector<int> jer(J); 

  for(int a=0; a<J; a++){
    char sz; cin>>sz; 
    jer[a]=size(sz); 
  }

  while(A--){
    char s; cin>>s; 
    int jNum, siz; cin>>jNum; 
    siz=size(s); 
    if(jer[jNum-1]>=siz) {ans++; jer[jNum-1]=-1;}
  }
  cout<<ans<<endl; 
}