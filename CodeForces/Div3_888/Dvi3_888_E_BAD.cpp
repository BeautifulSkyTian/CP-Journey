#include <bits/stdc++.h>
using namespace std; 

vector<vector<int>> brew1; 
vector<int> cost1; 
vector<int> brewCost; 
vector<int> vis; 

void dfs(int potion){
    for(int node: brew1[potion]){
        if(brew1[node].size()==0){
            brewCost[potion]+=cost1[node];
            cout<<'i'<<cost1[node]; 
        }
        else if(brewCost[node]!=-1){
            if(brewCost[node]<cost1[node]) {brewCost[potion]+=brewCost[node]; cout<<'j'; }
            else {brewCost[potion]+=cost1[node]; cout<<'k'; }
        }
        else{
            dfs(node); 
            cout<<'l';
            if(brewCost[node]<cost1[node]) brewCost[potion]+=brewCost[node];
            else brewCost[potion]+=cost1[node];
        }
    }
    vis[potion]=1; 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 

    for(int a=0; a<N; a++){
        int n, k; cin>>n>>k; 

        vector<int> cost(n+1); 
        brewCost=cost; 
        vis=cost; 
        fill(brewCost.begin(), brewCost.end(), -1); 
        for(int b=1; b<n+1; b++) cin>>cost[b]; 
        for(int b=0; b<k; b++){
            int x; cin>>x; 
            cost[x]=0; 
        }cost1=cost; 

        vector<vector<int>> brew(n+1);
        for(int b=1; b<n+1; b++){
            int x; cin>>x; 
            for(int c=0; c<x; c++){
                int y; cin>>y; 
                brew[b].push_back(y); 
            }
        } brew1=brew; 

        for(int b=1; b<n+1; b++){
            if(brew[b].size()==0){
                cout<<cost[b]<<" "; 
            }
            else{
                if(vis[b]){
                    if(brewCost[b]<cost1[b]) cout<<brewCost[b]<<" "; 
                    else cout<<cost1[b]<<" "; 
                }
                else{
                    cout<<brew[b].size(); 
                    dfs(b); 
                    if(brewCost[b]<cost1[b]) cout<<brewCost[b]<<" "; 
                    else cout<<cost1[b]<<" "; 
                }
            }
        }
        cout<<endl; 
    }
}