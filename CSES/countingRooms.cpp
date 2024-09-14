#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(); 

    int N, M; cin>>N>>M; 

    vector<vector<int>> graph(N+2, vector<int>(M+2, 1)); 
    vector<pair<int, int>> zero; 

    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
            char x; cin>>x; 
            if(x=='.') {graph[a+1][b+1]=0; zero.push_back({a+1, b+1});}
        }
    }
    /*cout<<endl; 
    for(int a=0; a<N+2; a++){
        for(int b=0; b<M+2; b++) cout<< graph[a][b]; 
        cout<<endl; 
    }*/

    int rooms=0; 
    queue<pair<int, int>> dir; 
    pair<int, int> node; 
    for(int a=0; a<zero.size(); a++){
        if(!graph[zero[a].first][zero[a].second]){
            dir.push({zero[a].first, zero[a].second}); 
            graph[zero[a].first][zero[a].second]=1; 
            while(dir.size()>0){
                node=dir.front(); dir.pop(); 

                if(!graph[node.first-1][node.second]) {
                    graph[node.first-1][node.second]=1; 
                    dir.push({node.first-1, node.second});
                }
                if(!graph[node.first+1][node.second]) {
                    graph[node.first+1][node.second]=1; 
                    dir.push({node.first+1, node.second});
                }
                if(!graph[node.first][node.second+1]) {
                    graph[node.first][node.second+1]=1; 
                    dir.push({node.first, node.second+1});
                }
                if(!graph[node.first][node.second-1]) {
                    graph[node.first][node.second-1]=1; 
                    dir.push({node.first, node.second-1});
                }
            } 
            rooms++; 
        }
    }
    cout<<rooms<<endl; 
}