#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        vector<vector<int>> ar; 
        char x; cin>>x; ar.push_back({x, 1}); 

        for(int a=0; a<n-1; a++){
            cin>>x; 
            if(x!=ar[ar.size()-1][0]) ar.push_back({x, 1}); 
            else ar[ar.size()-1][1]++; 
        }
        // for(vector<int> i: ar) cout<<i[1]<<" "; 


        if(ar.size()==1 && ar[0][0]=='B') cout<<n<<endl; 
        else if(ar[0][0]=='W' && ar[ar.size()-1][0]=='W'){
            cout<<n-ar[0][1]-ar[ar.size()-1][1]<<endl; 
        }
        else if(ar[0][0]=='B' && ar[ar.size()-1][0]=='B'){
            cout<<n<<endl; 
        }
        else if(ar[0][0]=='W' && ar[ar.size()-1][0]=='B'){
            cout<<n-ar[0][1]<<endl; 
        }
        else if(ar[0][0]=='B' && ar[ar.size()-1][0]=='W'){
            cout<<n-ar[ar.size()-1][1]<<endl; 
        }
        
    }
}