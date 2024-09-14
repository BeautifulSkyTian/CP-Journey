#include <bits/stdc++.h>
using namespace std; 

vector<int> graph; 

int find(int v){
    return v==graph[v]? v: graph[v]=find(graph[v]); 
}

void union_set(int a, int b){
    a=find(a); 
    b=find(b); 
    if(a!=b){
        graph[a]=b; 
    }
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("factory.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("factory.out", "w", stdout);

    int n; cin>>n; 
    graph.resize(n+1, 0); 

    for(int a=1; a<=n; a++) graph[a]=a; 
    
    vector<int> ar; 
    for(int a=0; a<n-1; a++){
        int x, y; cin>>x>>y; 
        ar.push_back(x); 
        union_set(x, y); 
    }

    int ans=find(ar[0]); 
    for(int a=1; a<ar.size(); a++){
        int v=find(ar[a]); 
        if(v!=ans){
            cout<<-1<<endl; 
            return 0; 
        }
        ans=v; 
    }
    cout<<ans<<endl; 
}