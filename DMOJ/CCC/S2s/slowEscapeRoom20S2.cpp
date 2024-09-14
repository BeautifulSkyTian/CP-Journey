#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int R, C; cin>>R>>C; 
    
    vector<vector<int>> graph(R, vector<int>(C)); 
    vector<vector<int>> visited(R, vector<int>(C, 0)); 
    for(int a=0; a<R; a++){
        for(int b=0; b<C; b++) cin>>graph[a][b]; 
    }

    queue<pair<int, int>> dir; 
    pair<int, int> node; 

    bool urMom=false; 
    dir.push({0, 0}); 
    while(dir.size()>0){
        int a=0;
        node=dir.front(); 
        if(node.first==R-1 && node.second==C-1) {urMom=true; break;}

        dir.pop(); 
        int alpha=graph[node.first][node.second]; //3

        char valid; 
        if(R>=C) valid='R'; //C
        else valid='C'; 

        for(int x=1; x<=max(R, C) && x<=alpha; x++){
            a=alpha/x; 
            if(alpha%x==0 && a<=min(R, C)){
                if(valid=='R' && !visited[x-1][a-1]) {dir.push({x-1, a-1}); visited[x-1][a-1]=1;}
                else if(valid=='C' && !visited[a-1][x-1]) {dir.push({a-1, x-1}); visited[a-1][x-1]=1;}
            }
        }
    }
    if(urMom) cout<<"yes"<<endl; 
    else cout<<"no"<<endl; 
}