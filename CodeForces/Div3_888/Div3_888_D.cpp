#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 

    for(int a=0; a<N; a++){
        int n; cin>>n; 

        vector<long long> psa(n-1); 
        for(int b=0; b<n-1; b++) cin>>psa[b]; 

        vector<int> vis(n+1); 
        vector<long long> sus; 
        
        if(psa[0]>n) sus.push_back(psa[0]); 
        else vis[psa[0]]=1; 
        for(int b=1; b<n-1; b++){
            long long dif=psa[b]-psa[b-1]; 
            
            if(dif>n || vis[dif]) sus.push_back(dif); 
            else vis[dif]=1; 
        }
        
        if(!sus.size()) cout<<"YES"<<endl; 
        else if(sus.size()>1) cout<<"NO"<<endl; 
        else{
            vector<int> x; 
            for(int b=1; b<=n; b++){
                if(!vis[b]) x.push_back(b);
            }
            if(x[0]+x[1]==sus[0]) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
    }
}