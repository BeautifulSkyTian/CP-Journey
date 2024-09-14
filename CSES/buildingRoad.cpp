#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, M; cin>>N>>M; 

    vector<vector<int>> graph(N+1); //each position represents a node. This basically creates an adjacency list. 
    vector<int> trace(N+1, 0); //A vector where each position represents whether a node is already viewed or not. 

    for(int a=0; a<M; a++){
        int x,y; cin>>x>>y;       
        graph[x].push_back(y); //Adds the nieghbours of a node to position a; 
        graph[y].push_back(x); 
    }

    // for(int a=1; a<=a+1; a++){
    //     cout<<a<<": "; 
    //     for(int b=0; b<graph[a].size(); b++) cout<<graph[a][b]<<" "; 
    //     cout<<endl; 
    // }

    vector<pair<int, int>> roads; 
    queue<int> dir; dir.push(1); 
    int node, cnt=0; 
    bool stop=false; 
    int x=1; 
    while(cnt!=N){
        while(dir.size()>0){ //This is bfs because i would have to discover to the end of each node. 
            node=dir.front(); 
            dir.pop(); 
            cnt++; 
            if(cnt==N) {stop=true; break;}

            trace[node]=1; 
            for(int a: graph[node]){
                if(!trace[a]) {dir.push(a); trace[a]=1;} //This adds the neighbours of a node in to the queue. 
                //It's better to do it like this instead of assigning a node to be visited when viewing a node. 
                //In this case, when a neighbour is pushed, that neighbour can no longer be used again which is much more efficient.
            }
        }
        if(stop) break; 

        for(;x<=N+1; x++){ //to solve tle, we recorded down the nodes we already checked. No need to start from 1. 
            if(!trace[x]){
                dir.push(x); 
                roads.push_back({node, x}); //Once the bfs gets to the end. it would connect a new node that was not the neighbour 
                //of the previous node. And then push the 'node' and this node at [x] which means there is a road/connection 
                //between them. 
                break;
            }
        }
    }

    cout<<roads.size()<<endl; 
    for(pair<int, int> i: roads) cout<<i.first<<" "<<i.second<<endl; 
}