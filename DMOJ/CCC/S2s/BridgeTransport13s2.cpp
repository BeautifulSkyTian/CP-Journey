#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W,ans=0; 
  cin>>W>>N; 
  vector<int> car(N); 

  for(int a=0; a<N; a++) cin>>car[a]; 

  if(N<=4){
    int weight=0; 
    for(int a=0; a<N; a++){
      weight+=car[a]; 
      if(weight<=W) ans++; 
      else break; 
    }
  }  
  else{
    int valid=0; 
    for(int a=0; a+3<N; a++){
      int x=0; 
      if(valid==0){
        for(int b=0; b<4; b++){
          x+=car[b]; 
          if(x<=W) {ans++; valid=1;} 
          else {valid=0; break;}
        }
      }
      if(valid){
        int weight=car[a]+car[a+1]+car[a+2]+car[a+3]; 
        if(weight>W){ans=a+3+1-1; break;}
        else ans=a+3+1;
      }
      else break;
    }
  }
  cout<<ans<<endl;
}