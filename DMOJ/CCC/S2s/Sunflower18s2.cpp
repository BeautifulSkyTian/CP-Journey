#include <bits/stdc++.h>
using namespace std;

long pos; 

bool srt(vector<long> a, vector<long> b){
  return a[pos]<b[pos]; 
}

int main() {
  vector<vector<long>> chart; 
  long n,valid;

  cin>>n; 
  chart.resize(n, vector<long>(n)); 
  for(long a=0; a<n; a++){
    for(long b=0; b<n; b++) cin>>chart[a][b]; 
  }

  pos=0; 
  if(is_sorted(chart[0].begin(), chart[0].end()) && is_sorted(chart.begin(), chart.end(), srt)){
    for(long a=0; a<n; a++){
      for(long b=0; b<n; b++) cout<<chart[a][b]<<" ";
      cout<<endl; 
      valid=1; 
    }
  } else valid=0; 

    pos=n-1; 
  if(valid==0 && is_sorted(chart[0].rbegin(), chart[0].rend()) && is_sorted(chart.begin(), chart.end(), srt)){
    for(long a=n-1; a>=0; a--){
      for(long b=0; b<n; b++) cout<<chart[b][a]<<" ";
      cout<<endl; 
      valid=1; 
    }
  } else valid=0; 

    pos=0; 
  if(valid==0 && is_sorted(chart[n-1].begin(), chart[n-1].end()) && is_sorted(chart.rbegin(), chart.rend(), srt)){
    for(long a=0; a<n; a++){
      for(long b=n-1; b>=0; b--) cout<<chart[b][a]<<" ";
      cout<<endl; 
      valid=1; 
    }
  } else valid=0; 

      pos=n-1; 
  if(valid==0 && is_sorted(chart[n-1].rbegin(), chart[n-1].rend()) && is_sorted(chart.rbegin(), chart.rend(), srt)){
    for(long a=n-1; a>=0; a--){
      for(long b=n-1; b>=0; b--) cout<<chart[a][b]<<" ";
      cout<<endl; 
      valid=1; 
    }
  } else valid=0; 
}