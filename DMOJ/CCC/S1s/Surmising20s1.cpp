#include <bits/stdc++.h>
using namespace std;

bool srt(pair<double, double>a, pair<double, double>b){
  return a.first< b.first; 
}

int main(){
  int N;
  vector<pair<double, double>> obv; 
  vector<double> speed; 

  cin>>N;
  obv.resize(N); 
  for(int a=0; a<N; a++){
    cin>>obv[a].first; 
    cin>>obv[a].second;
  }

  sort(obv.begin(), obv.end(), srt); 
  //for(pair<double, double> a: obv) cout<<a.first<<" "<<a.second<<endl;
  for(int a=1; a<N; a++){
    speed.push_back(abs(obv[a].second-obv[a-1].second)/(obv[a].first-obv[a-1].first)); 
  }
  sort(speed.begin(), speed.end()); 
  cout<<fixed<<setprecision(1)<<speed[speed.size()-1]<<endl;
}