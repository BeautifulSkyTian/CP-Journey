#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int x; cin>>x; 

  while(true){
    x++; 
    string str=to_string(x); 

    vector<int> table(58); 
    for(int a=0; a<str.size(); a++) table[str[a]]++; 

    bool valid=true; 
    for(int a=48; a<=57; a++) if(table[a]>1){valid=false; break;}
    if(valid) {cout<<str<<endl; break;}
    
  }
  
}