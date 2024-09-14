#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, M; cin>>N>>M; 
    pair<int, int> start, exit; 
    vector<vector<int>> graph(N+2, vector<int>(M+2, 1)); 

    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
            char x; cin>>x; 
            if(x=='.') graph[a+1][b+1]=0; 
            else if(x=='A') {graph[a+1][b+1]=0; start={a+1, b+1};}
            else if(x=='B') {graph[a+1][b+1]=0; exit={a+1, b+1};} 
        }
    }

    /*for(int a=0; a<N+2; a++){
        for(int b=0; b<M+2; b++) cout<<graph[a][b]; 
        cout<<endl; 
    }*/

    int nb=1;
    int curNb=0; 
    int nodeCount=0; 
    bool YN=false, stop=false; 
    queue <pair<int, int>> dir; dir.push(start); 
    pair<int, int> node; 
    vector<vector<pair<int, int>>> trace(2, vector<pair<int, int>>(1, start));  

    while(dir.size()>0){
        vector<pair<int, int>> temp; 
        for(int a=0; a<nb; a++){
            node=dir.front(); dir.pop(); 
            nodeCount++; 

            if(node==exit) {YN=true; stop=true; break;}

            if(!graph[node.first-1][node.second]) {
                graph[node.first-1][node.second]=1; 
                dir.push({node.first-1, node.second});
                curNb++;
                temp=trace[nodeCount]; 
                temp.push_back({node.first-1, node.second}); 
                trace.push_back(temp); 
            }
            if(!graph[node.first+1][node.second]) {
                graph[node.first+1][node.second]=1; 
                dir.push({node.first+1, node.second});
                curNb++;
                temp=trace[nodeCount]; 
                temp.push_back({node.first+1, node.second}); 
                trace.push_back(temp);
            }
            if(!graph[node.first][node.second+1]) {
                graph[node.first][node.second+1]=1; 
                dir.push({node.first, node.second+1});
                curNb++;
                temp=trace[nodeCount]; 
                temp.push_back({node.first, node.second+1}); 
                trace.push_back(temp);
            }
            if(!graph[node.first][node.second-1]) {
                graph[node.first][node.second-1]=1; 
                dir.push({node.first, node.second-1});
                curNb++;
                temp=trace[nodeCount]; 
                temp.push_back({node.first, node.second-1}); 
                trace.push_back(temp);
            }
        }
        if(stop) break; 
        nb=curNb; 
        curNb=0; 
    }

    if(YN) {
        cout<<"YES"<<endl<<trace[nodeCount].size()-1<<endl; 
        string path=""; 
        for(int a=0; a<trace[nodeCount].size()-1; a++){
            int b=a+1; 
            if(trace[nodeCount][b].first>trace[nodeCount][a].first) path+="D"; 
            else if(trace[nodeCount][b].first<trace[nodeCount][a].first) path+="U"; 
            else if(trace[nodeCount][b].second>trace[nodeCount][a].second) path+="R"; 
            else if(trace[nodeCount][b].second<trace[nodeCount][a].second) path+='L'; 
        }
        cout<<path<<endl; 
    }
    else cout<<"NO"<<endl; 

    //for(pair<int, int> i: trace[nodeCount]) cout<<i.first<<" "<<i.second<<endl; 
}