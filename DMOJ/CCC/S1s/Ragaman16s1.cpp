#include <bits/stdc++.h>
using namespace std;

int main(){
  int num_ocr=0;
  string first, second; 

  cin>>first>>second;
  for(int a=0; a<first.size(); a++){
    if(second.find(second[a])==a){
      if(count(second.begin(),second.end(),second[a])<=count(first.begin(),first.end(),second[a]) || second[a]=='*')
        num_ocr+=count(second.begin(),second.end(),second[a]); 
    else break;
    }
  }
  if(num_ocr==first.size()) cout<<'A'<<endl;
  else cout<<'N'<<endl;
}