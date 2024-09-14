#include <bits/stdc++.h>
using namespace std;

int main() {
  string aromatic;
  int sum;
  map<char, int> romatic{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}}; 
  
  cin>>aromatic; 
  sum=romatic[aromatic[aromatic.size()-1]]*(aromatic[aromatic.size()-2]-'0');
//  cout<<sum<<endl;
  for(int a=0; a<aromatic.size()-2; a+=2){
    if(romatic[aromatic[a+1]]<romatic[aromatic[a+3]]){
      sum-=(aromatic[a]-'0')*romatic[aromatic[a+1]];
    }
    else sum+=(aromatic[a]-'0')*romatic[aromatic[a+1]];
  }
  cout<<sum<<endl;
}