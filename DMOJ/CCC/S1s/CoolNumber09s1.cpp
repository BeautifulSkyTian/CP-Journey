#include <bits/stdc++.h>
using namespace std;

int main(){
  int a; cin>>a;
  int b; cin>>b;
  int sqrted;
  int cubrted;
  int coolNum=0;
  
  for(; a<=b; a++){
    sqrted=sqrt(double(a)) + 1e-9;
    cubrted=cbrt(double(a)) + 1e-9; 
    if(sqrted*sqrted==a && cubrted*cubrted*cubrted==a)
      coolNum++;
  }
  cout<<coolNum;
}

// ceilpow(a, 1/2)
// pow(a, 1/3)