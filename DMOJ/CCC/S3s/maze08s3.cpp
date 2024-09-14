#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, row, column; cin>>N; 

    for(int z=0; z<N; z++)
    {cin>>row>>column; 
    vector<string> graph(row+2); 
    vector<vector<int>> visited(row+2, vector<int>(column+2, 0)); 
    pair<int, int> node; 
    queue<pair<int, int>> direc; 

    /*for(vector<int> i: visited){
        for(int k: i) cout<<k<<" "; 
        cout<<endl; 
    }*/

    string str(column+2, '*'); 
    graph[0]=str; 
    graph[row+1]=str; 

    for(int a=1; a<row+1; a++){
        string input; cin>>input; 
        input.insert(0, "*"); 
        input.push_back('*'); 
        graph[a]=input; 
    } 
    
    int nb=1, inter=1; 
    int curNb=1; 
    int a=1; 
    bool urMom=true, valid=false; 
    direc.push({1, 1}); visited[1][1]=1;
    while(direc.size()>0){
        for(; a<=curNb; a++){
            node=direc.front(); 
            //cout<<node.first<<' '<<node.second<<endl;

            if(node.first==row && node.second==column){
                urMom=false; 
                valid=true; 
                break;
            }

            if(graph[node.first][node.second]=='+'){
                if(!visited[node.first][node.second-1] && graph[node.first][node.second-1]!='*') 
                {direc.push({node.first, node.second-1}); nb++; visited[node.first][node.second-1]=1; }
                if(!visited[node.first][node.second+1] && graph[node.first][node.second+1]!='*') 
                {direc.push({node.first, node.second+1}); nb++; visited[node.first][node.second+1]=1; }
                if(!visited[node.first-1][node.second] && graph[node.first-1][node.second]!='*') 
                {direc.push({node.first-1, node.second}); nb++; visited[node.first-1][node.second]=1; } 
                if(!visited[node.first+1][node.second] && graph[node.first+1][node.second]!='*') 
                {direc.push({node.first+1, node.second}); nb++; visited[node.first+1][node.second]=1; } 
            }
            else if(graph[node.first][node.second]=='-'){
                if(!visited[node.first][node.second-1] && graph[node.first][node.second-1]!='*') 
                {direc.push({node.first, node.second-1}); nb++; visited[node.first][node.second-1]=1; }
                if(!visited[node.first][node.second+1] && graph[node.first][node.second+1]!='*') 
                {direc.push({node.first, node.second+1}); nb++; visited[node.first][node.second+1]=1; }
            }
            else if(graph[node.first][node.second]=='|'){
                if(!visited[node.first-1][node.second] && graph[node.first-1][node.second]!='*') 
                {direc.push({node.first-1, node.second}); nb++; visited[node.first-1][node.second]=1; } 
                if(!visited[node.first+1][node.second] && graph[node.first+1][node.second]!='*') 
                {direc.push({node.first+1, node.second}); nb++; visited[node.first+1][node.second]=1; } 
            }

            direc.pop(); 
        }
        if(!urMom) break; 
        curNb=nb; 
        inter++; 
    }
    if(valid)cout<<inter<<endl;
    else cout<<"-1"<<endl; 
    }
}