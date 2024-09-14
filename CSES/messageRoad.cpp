#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, M; cin>>N>>M; 
    vector<vector<int>> graph(N+1); 
    vector<int> visited(N+1, 0); 
    vector<int> backTrack(N+1); 

    for(int a=0; a<M; a++){
        int x, y; cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }

    // for(int a=1; a<=N; a++){
    //     cout<<a<<": "; 
    //     for(int b=0; b<graph[a].size(); b++) cout<<graph[a][b]; 
    //     cout<<endl; 
    // }

    queue<int> dir; dir.push(1); 
    int node; 
    bool YN=false; 
    while(dir.size()>0){
        node=dir.front(); dir.pop(); 
        if(node==N) {YN=true; break;}

        visited[node]=1; 
        for(int i: graph[node]){
            if(!visited[i]){ //Please make sure to not put visited[node] because we are supposed to view the neighbours of node. Not the node itself.LOL.
                dir.push(i); //Since I have created an adjacency list, all I have to do is push the neighbours of a node. 
                visited[i]=1; //Then I will make the nieghbours to marked as visited in the visited vector. 
                backTrack[i]=node;  //Since neighbours of the node belong to that node, all I need to do is assign the value of 
                //the node to  backTrack[x]. X would be the neighbour of the node. This makes it so the backTrack vector's each 
                //element shows a path of how one node gets to another. It is like Labyrinth. 
            }
        }
    }
    if(YN){
        vector<int> path; 
        for(int x=node;;){
            path.push_back(x); 

            if(x==1){
                reverse(path.begin(), path.end()); //This is just like Labyrinth, because say a node is marked 2, this node points 
                //to node, 2, meaning it came from node 2. Which means the only way to get the path is to go backwars and back track
                break; //Then I just need to reverse the path which would get me the acutal path. 
            }
            else x=backTrack[x]; 
        }
        cout<<path.size()<<endl;
        for(int a: path) cout<<a<<" "; 
        cout<<endl; 
    }
    else cout<<"IMPOSSIBLE"<<endl; 
}