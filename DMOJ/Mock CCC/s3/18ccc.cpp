#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 
    
    int n, m; cin>>n>>m; 
    vector<vector<int>> graph(n+1); 
    vector<pair<int,int>> edge; 
    for(int a=0; a<m; a++){
        int x, y; cin>>x>>y; 
        graph[x].push_back(y); 
        edge.push_back({x, y});
    }

    for(int a=0; a<m; a++){
        vector<int> vis(n+1); 
        queue<int> dir; 
        int node=0; 
        dir.push(1); 
        
        bool valid=false; 
        while(dir.size()>0){
            node=dir.front(); dir.pop(); 
            
            if(node==n){
                cout<<"YES"<<endl; 
                valid=true; 
                break;
            }
            
            vis[node]=1; 
            for(int i: graph[node]){
                if(!vis[i] && !(node==edge[a].first && i==edge[a].second)) dir.push(i); 
            }
        }
        if(!valid) cout<<"NO"<<endl; 
    }

}