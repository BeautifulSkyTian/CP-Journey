#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    vector<vector<int>> graph(27, vector<int>(27, 0)); 
    int N, R, C; cin>>N>>R>>C; 

    for(int a=1; a<=R; a++){
        for(int b=1; b<=C; b++){
            char x; cin>>x; 
            if(x=='.') graph[a][b]=1; 
        }
    }
    
    vector<int> room; 
    for(int a=1; a<=R; a++){
        for(int b=1; b<=C; b++){
            queue<pair<int, int>> dir; 
            pair<int, int> node; 
            int floor=0; 
            
            if(graph[a][b]){
                floor++; 
                graph[a][b]=0; 
                dir.push({a, b}); 
                while(dir.size()>0){
                    node=dir.front(); 
                    dir.pop(); 

                    if(graph[node.first][node.second-1]){
                        dir.push({node.first, node.second-1}); floor++; 
                        graph[node.first][node.second-1]=0;
                    }
                    if(graph[node.first][node.second+1]){
                        dir.push({node.first, node.second+1}); floor++; 
                        graph[node.first][node.second+1]=0; 
                    }
                    if(graph[node.first+1][node.second]){
                        dir.push({node.first+1, node.second}); floor++; 
                        graph[node.first+1][node.second]=0; 
                    }
                    if(graph[node.first-1][node.second]){
                        dir.push({node.first-1, node.second}); floor++; 
                        graph[node.first-1][node.second]=0; 
                    }
                }
                room.push_back(floor); 
            }
        }
    }

    sort(room.begin(), room.end(), greater<int>()); 
    for(int a=0; a<room.size(); a++){
        N-=room[a]; 
        if(N==0){
            if(a+1==1) {cout<<a+1<<" room, "<<N<<" square metre(s) left over" <<endl; return 0; }
            else {cout<<a+1<<" rooms, "<<N<<" square metre(s) left over" <<endl; return 0; }
        }
        else if(N<0){
            if(a==1){
                cout<<a<<" room, "<<N+room[a]<<" square metre(s) left over" <<endl;
                return 0;  
            }
            else{
                cout<<a<<" rooms, "<<N+room[a]<<" square metre(s) left over" <<endl;
                return 0;  
            }
        }
    }
    if(N>0){
        if(room.size()==1) {cout<<room.size()<<" room, "<<N<<" square metre(s) left over" <<endl; return 0; }
        else {cout<<room.size()<<" rooms, "<<N<<" square metre(s) left over" <<endl; return 0; }
    }
}