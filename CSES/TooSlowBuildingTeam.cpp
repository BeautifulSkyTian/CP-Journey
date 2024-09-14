#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin>>N>>M; 

    vector<vector<int>> graph(N+1,vector<int>(0)); 
    vector<int> group(N+1, 0); 
    vector<int> trace(N+1, 0); 

    for(int a=1; a<=M; a++){
        int x, y; cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }

    // for(int a=1; a<=N; a++){
    //     cout<<a<<": "; 
    //     for(int b: graph[a]) cout<<b<<" "; 
    //     cout<<endl; 
    // }

    queue<vector<int>> dir; dir.push({1, 0}); group[1]=1; 
    int node, distance, cnt=0, x=1; 
    bool stop1=false, stop2=false; 

    while(cnt!=N){
        vector<vector<int>> D; 
        while(dir.size()>0){
            node=dir.front()[0]; distance=dir.front()[1];
            D.resize(distance+2); 
            dir.pop(); 
            trace[node]=1; 
            //cout<<"Node: "<<node<<"\n"; 
            cnt++; 

            if(cnt==N) {stop1=true; break;}

            for(int a:graph[node]){
                if(count(D[distance].begin(), D[distance].end(), a)>0) {stop2=true; break;}
                if(!trace[a]){
                    dir.push({a, distance+1}); 
                    trace[a]=1; 
                    D[distance+1].push_back(a); 
                    if((distance+1)%2!=0) group[a]=2; 
                    else group[a]=1;
                }
            }
            if(stop2) break;
        }
        if(stop1 || stop2) break; 
        
        for(;x<=N; x++){
            if(!trace[x]) {dir.push({x, 0}); group[x]=1; break;}
        }
    }

    if(stop1){
        for(int a=1; a<=N; a++) cout<<group[a]<<" "; 
        cout<<endl; 
    }
    else cout<<"IMPOSSIBLE"<<endl; 
}