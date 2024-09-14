#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, numS=0, numT=0;
  string str;

  cin>>N;
  cin.ignore();
  for(int a=0; a<N; a++){
    getline(cin, str);
   // cout<<str<<endl;
    for(char b: str){
      if(b=='S' || b=='s') numS++;
      if(b=='t' || b=='T') numT++;
    }
  }
  if(numT>numS) cout<<"English"<<endl;
  else if(numT<numS) cout<<"French"<<endl;
  else if(numT==numS) cout<<"French"<<endl;
}