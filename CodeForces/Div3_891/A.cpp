#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 

    while(T--){
        int n; cin>>n; 
        int odd=0, even=0; 
        for(int a=0; a<n; a++){
            int x; cin>>x; 
            if(x%2) odd++; 
            else even++; 
        }

        if(odd%2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl; 
    }
}