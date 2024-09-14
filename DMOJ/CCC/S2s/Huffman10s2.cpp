#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 

    map<string, string> decode; 

    for(int a=0; a<N; a++){
        string x, b; 
        cin>>b>>x; 

        decode[x]=b; 
    }
    
    string mystery; cin>>mystery; 
    for(int pos=0, length=1; pos<mystery.size();){
        string str=mystery.substr(pos, length); 

        if(decode[str]!=""){
            cout<<decode[str]; 
            pos+=length; 
            length=1; 
        }
        else length++; 
    }

}