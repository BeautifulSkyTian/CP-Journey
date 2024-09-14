#include <bits/stdc++.h>
using namespace std;

int main(){
  string direction;
  vector<int> board{1, 2, 3, 4}; 

  cin>>direction;
  for(char a: direction){
    if(a=='H'){
      swap(board[0], board[2]);
      swap(board[1], board[3]); 
    } 
    if(a=='V'){
      swap(board[0], board[1]);
      swap(board[2], board[3]); 
    }
  }

  cout<<board[0]<<" "<<board[1]<<endl<<board[2]<<" "<<board[3]<<endl;
}