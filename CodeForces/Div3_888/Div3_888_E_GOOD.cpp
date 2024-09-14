#include <bits/stdc++.h>
using namespace std; 

const int MAXN=2e5; 

vector<vector<int>> brew(MAXN+1); 
vector<long long> cost(MAXN+1), ans(MAXN+1); 
vector<int> vis(MAXN+1); 

long long solve(int potion){
    if(brew[potion].size()==0 && !vis[potion]) vis[potion]=1, ans[potion]=cost[potion]; 
    if(vis[potion]) return ans[potion]; 
    for(int node: brew[potion]) ans[potion]+=solve(node); 
    ans[potion]=min(ans[potion], cost[potion]); 
    vis[potion]=1; 
    return ans[potion]; 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 

    while(T--){
        int n, k; cin>>n>>k; 

        fill(ans.begin(), ans.end(), 0); 
        fill(vis.begin(), vis.end(), 0); 

        for(int a=1; a<n+1; a++) brew[a].clear(); 
        
        for(int a=1; a<n+1; a++) cin>>cost[a]; 
        for(int a=0, x; a<k; a++) cin>>x, vis[x]=1; 

        for(int a=1; a<n+1; a++){
            int x; cin>>x; 
            for(int b=0, y; b<x; b++) cin>>y, brew[a].push_back(y); 
        }

        for(int a=1; a<n+1; a++) cout<<solve(a)<<" "; 
        cout<<endl; 

    }
}