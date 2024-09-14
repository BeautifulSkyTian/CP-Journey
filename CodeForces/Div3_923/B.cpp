#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        vector<char> str(n); 
        int x=0; 
        for(int a=0; a<n; a++){
            int i; cin>>i; i--;
            if(i==-1){
                str[a]=x+97; 
                x++; 
            }
            else{
                str[a]=str[i]; 
            }
        }

        for(char i: str) cout<<i; 
        cout<<endl; 
    }
}