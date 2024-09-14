#include <bits/stdc++.h>
using namespace std;

int main(){
  string father; cin>>father;
  string mother; cin>>mother;
  int N; cin>>N;
  bool valid;
  string baby;

  for(int a=0; a<N; a++){
    cin>>baby;
//    cout<<baby<<endl;
    for(int b=0; b<5; b++){
      if(isupper(baby[b])){
        if(father.find(baby[b])!=string::npos || mother.find(baby[b])!=string::npos) valid=true;
        else{
          valid=false;
          break;
        }
      }
      else{
        if(father.find(baby[b])!=string::npos && mother.find(baby[b])!=string::npos) valid=true;
        else{
          valid=false;
          break;
        }
      }
    }
    if(valid==true) cout<<"Possible baby."<<endl;
    else cout<<"Not their baby!"<<endl;
  }
}

//If baby has shows lower case, then the baby should receive all lower case from each of its parents. Meaning, both parents shoudl have a lower case. 
  //If baby shows upper case, then the baby definitely receives an upper case from its parent. The baby would receive either another upper case or possibly a lower case from its parent. As long as its parent has a upper, this condition would be true. No matter what, the baby will always show upper case if it has one.