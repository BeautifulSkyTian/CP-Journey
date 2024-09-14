#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int R, C; cin>>R>>C; 
    
    vector<vector<int>> graph(R, vector<int>(C)); 
    vector<vector<int>> visited(R, vector<int>(C, 0)); 
    vector<vector<pair<int, int>>> cnt(1000001); 
    for(int a=0; a<R; a++){
        for(int b=0; b<C; b++){
            int x; cin>>x; 
            graph[a][b]=x; cnt[x].push_back({a, b}); 
        }
    }

    queue<pair<int, int>> dir; 
    pair<int, int> node; 

    bool urMom=false; 
    dir.push({R-1, C-1}); //dir.push({0, 0}); 
    visited[R-1][C-1]=1; 
    while(dir.size()>0){
        node=dir.front(); 
        if(node.first==0 && node.second==0) {urMom=true; break;}//if(node.first==R-1 && node.second==C-1) {urMom=true; break;}

        dir.pop(); 
        int alpha=(node.first+1)*(node.second+1); 
        //If the ending destination is (4, 3). then that means the number which it comes from must be 12. 
        
        for(pair<int, int>i: cnt[alpha]){
                if(!visited[i.first][i.second]) {dir.push({i.first, i.second}); visited[i.first][i.second]=1;}
        }
    }
    if(urMom) cout<<"yes"<<endl; 
    else cout<<"no"<<endl; 
}