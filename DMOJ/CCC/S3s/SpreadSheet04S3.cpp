#include <bits/stdc++.h>
using namespace std; 

vector<vector<vector<int>>> graph(10, vector<vector<int>>(9, vector<int>()));
vector<vector<int>> valid(10, vector<int>(9, 1)); 
vector<vector<int>> vis(10, vector<int>(9, 0)); 

int dfs(pair<int, int> node){
    int x=node.first, y=node.second; 

    if(valid[x][y]) return 0; 
    if(vis[x][y] && !valid[x][y]){
        graph[x][y].resize(0); 
        graph[x][y].push_back(1001);
        return 0; 
    }
    vis[x][y]=1; 

    int sum=0; 
    for(int a=0; a<graph[x][y].size()-1; a+=3){
        int m=graph[x][y][a], n=graph[x][y][a+1]; 
        if(graph[m][n][0]==1001){
            graph[x][y].resize(0); 
            graph[x][y].push_back(1001); 
            return 0; 
        }
        else dfs({m, n}); 
        
        if(graph[m][n][0]==1001){
            graph[x][y].resize(0); 
            graph[x][y].push_back(1001); 
            return 0; 
        }
        
        sum+=graph[m][n][0]; 
    }
    graph[x][y].resize(0); 
    graph[x][y].push_back(sum); 
    valid[x][y]=1; 
    return 0;
}

int main(){

    for(int a=0; a<10; a++){
        for(int b=0; b<9; b++){
            string n; cin>>n; 
            if(n[0]<64) graph[a][b].push_back(stoi(n)); 
            else{
                for(int c=0; c<n.size(); c++){
                    int m=n[c]; 
                    if(m>64 && m<91) graph[a][b].push_back(m-65); 
                    else graph[a][b].push_back(m-49); 
                }
                valid[a][b]=0; 
            }
        }
    }

    for(int a=0; a<10; a++){
        for(int b=0; b<9; b++){
            if(!valid[a][b] && graph[a][b][0]!=1001){
                vis.resize(0); 
                vis.resize(10, vector<int>(9, 0)); 
                dfs({a, b}); 
            }
        }
    }

    for(int a=0; a<10; a++){
        for(int b=0; b<9; b++){
            if(graph[a][b][0]==1001) cout<<"* "; 
            else cout<<graph[a][b][0]<<" "; 
        }
        cout<<endl; 
    }
}