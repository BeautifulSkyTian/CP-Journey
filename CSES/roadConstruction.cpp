#include <bits/stdc++.h>
using namespace std; 

int n, m;
vector<int> graph, size; 

int find_set(int v){
    return v==graph[v]? v: graph[v]=find_set(graph[v]); 
}

void DSU(int a, int b){
    a=find_set(a); 
    b=find_set(b); 

    if(a!=b){
        if(size[a]<size[b]) swap(a, b); 
        graph[b]=a; 
        size[a]+=size[b]; 
    }
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    cin>>n>>m; 
    graph.resize(n+1); 
    size.resize(n+1, 1); 

    for(int a=1; a<n+1; a++) graph[a]=a; 
    for(int a=0; a<m; a++){
        ans=0; 
        set<int> comp; 
        int x, y; cin>>x>>y;
        comp.insert(x), comp.insert(y); 
        DSU(x, y); 
        find_set(x), find_set(y); 

    }

}