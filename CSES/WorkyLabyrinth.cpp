#include <bits/stdc++.h> 
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, M; cin>>N>>M; 

    vector<vector<int>> graph(N+2, vector<int>(M+2, 1)); 
    vector<vector<char>> backTrack(N+2, vector<char>(M+2, '1')); 
    pair<int, int> start, exit; 

    for(int a=1; a<=N; a++){
        for(int b=1; b<=M; b++){
            char x; cin>>x; 
            if(x=='.') graph[a][b]=0; 
            else if(x=='A') {start={a, b}; graph[a][b]=0; }
            else if(x=='B') {exit={a, b}; graph[a][b]=0; }
        }
    }
    //cout<<"Start: "<<start.first<<" "<<start.second<<endl; 
    //cout<<"Exit: "<<exit.first<<" "<<exit.second<<endl; 

    queue<vector<int>> dir; dir.push({start.first, start.second, 0}); 
    pair<int, int> node; 
    bool YN=false; 
    int D; 
    while(dir.size()>0){
        node={dir.front()[0], dir.front()[1]}; 
        int distance=dir.front()[2]; 
        dir.pop(); 

        if(graph[node.first][node.second]) continue; 

        if(node.first==exit.first && node.second==exit.second){
            D=distance; 
            YN=true; 
            break; 
        }

        graph[node.first][node.second]=1; 
        if(!graph[node.first-1][node.second]){
            backTrack[node.first-1][node.second]='U'; 
            dir.push({node.first-1, node.second, distance+1}); 
        }
        if(!graph[node.first+1][node.second]){
            backTrack[node.first+1][node.second]='D'; 
            dir.push({node.first+1, node.second, distance+1}); 
        }
        if(!graph[node.first][node.second+1]){
            backTrack[node.first][node.second+1]='R'; 
            dir.push({node.first, node.second+1, distance+1}); 
        }
        if(!graph[node.first][node.second-1]){
            backTrack[node.first][node.second-1]='L'; 
            dir.push({node.first, node.second-1, distance+1}); 
        }

    }

    // for(int a=0; a<N+2; a++){
    //     for(int b=0; b<M+2; b++) cout<<backTrack[a][b]; 
    //     cout<<endl; 
    // }

    if(YN) {
        string path=""; 
        cout<<"YES"<<endl<<D<<endl; 
        for(int n=node.first, m=node.second;;){
            path+=backTrack[n][m]; 

            if(backTrack[n][m]=='R') m--; 
            else if(backTrack[n][m]=='L') m++; 
            else if(backTrack[n][m]=='U') n++; 
            else if(backTrack[n][m]=='D') n--; 
            else if(backTrack[n][m]=='1'){
                path=path.substr(0, path.size()-1); 
                reverse(path.begin(), path.end()); 
                break; 
            }
        }
        cout<<path<<endl; 
    }
    else cout<<"NO"; 
}