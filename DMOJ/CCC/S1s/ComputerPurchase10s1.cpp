#include <bits/stdc++.h>
using namespace std;

vector<pair<string, long>> PCs;

bool srt(pair<string,long> a, pair<string,long>b){
  if (a.second==b.second) return a.first<b.first;
  return a.second>b.second;
}

int main(){
  int N; cin>>N;
  string name;
  int R,S,D;
  pair<string, long> pcF; 

  for(int a=0; a<N; a++){
    cin>>name>>R>>S>>D;
    pcF.first=name;
    pcF.second=2*R+3*S+D;
    PCs.push_back(pcF);
    }
  if(N==0) ;
  else if(N==1)cout<<PCs[0].first;
  else{
    sort(PCs.begin(), PCs.end(), srt);
    cout<<PCs[0].first<<endl;
    cout<<PCs[1].first<<endl;
  }
}

/*
First enters. second and third would be both first.
Second Enters. If greater. Second and firs
*/