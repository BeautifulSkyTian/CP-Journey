#include <bits/stdc++.h>
using namespace std;

int main() {
  double x,alpha; 
  string strX; 
  int ways=0; 

  cin>>alpha; 
  for(int a=0; 5*a<=alpha; a++){
    x=(alpha-5*a)/4; 
    //strX=to_string(x); 
    //cout<<strX<<endl;
    if(x==(int)x){
      ways++; 
    }
  }
  cout<<ways<<endl;
}