#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        vector<vector<int>> ar(1, vector<int>(2)); 
        ar[0][0]=1; 
        char y; cin>>y; ar[0][1]=y; 
        
        for(int a=1; a<n; a++){
            char x; cin>>x; 
            if(x==ar[ar.size()-1][1]) ar[ar.size()-1][0]++; 
            else ar.push_back({1, x});   
        }

        // for(int a=0; a<ar.size(); a++) cout<<ar[a][0]<<" "<<ar[a][1]<<endl; 

        int ans=ar[0][0], ans1=0; 
        for(int a=1; a<ar.size(); a++){
            ans=max(ar[a][0], ans);
            if(ar[a][0]==1 && a+1<ar.size() && ar[a-1][1]==ar[a+1][1]) {ans1=max(ans1, (ar[a-1][0]+ar[a+1][0]+1));}
        }

        if(ans1>ans) cout<<ans1<<endl; 
        else{
            ans=ar.size()==1?ans:ans+1;
            cout<<ans<<endl; 
        }
    }
}