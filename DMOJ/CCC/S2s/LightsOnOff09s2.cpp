#include <bits/stdc++.h>
using namespace std;

int main() {
  int row, column, p; 
  cin>>row>>column; 

  set<vector<int>> prob; 
  vector<vector<int>> input(row, vector<int>(column, 0)); 
  vector<vector<int>> cp; 
  
  for(int a=0; a<row; a++){
    for(int b=0; b<column; b++) cin>>input[a][b]; 
  }
  cp=input; 

  p=row; 
  for(int a=1; a<row; a++){
    cp=input; 
    for(int b=a; b<row; b++){
      for(int c=0; c<column; c++){
        if(cp[b][c]==cp[b-1][c]) cp[b][c]=0; 
        else cp[b][c]=1; 
      }
    }
    prob.insert(cp[cp.size()-1]); 
    /*cout<<endl;
    for(vector<int> x:cp){
      for(int y:x) cout<<y<<" "; 
      cout<<endl; 
    }*/

    //if(cp[cp.size()-1]==input[input.size()-1]) p--; 
  }
  prob.insert(input[input.size()-1]); 
  /*cout<<endl;
  for(vector<int> x:prob){
      for(int y:x) cout<<y<<" "; 
      cout<<endl; 
    }*/
  
  cout<<prob.size()<<endl; 
}