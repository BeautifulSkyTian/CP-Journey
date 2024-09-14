#include <bits/stdc++.h>
using namespace std;

vector<int> graph; 
vector<int> sz; 

int find(int v){
  return v==graph[v]? v: graph[v]=find(graph[v]); 
}

void DSU(int a, int b){
  a=find(a); 
  b=find(b); 
  if(a!=b){
    if(sz[a]<sz[b]) swap(a, b); 
    graph[b]=a; 
    sz[a]+=sz[b]; 
  }
}

int main()
{
  cin.sync_with_stdio(0); 
  cin.tie(0); 

  freopen("wormsort.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("wormsort.out", "w", stdout);

  int n, m; cin>>n>>m; 
  vector<int> cow(n+1); 
  vector<int> visit(n+1); 
  graph.resize(n+1); 
  sz.resize(n+1, 1); 
  for(int a=1; a<=n; a++){
    int x; cin>>x; 
    cow[a]=x; 
    graph[a]=a; 
    if(x==a) visit[a]=1; 
  }

  if(is_sorted(cow.begin()+1, cow.end())) {cout<<-1<<endl; return 0; }
  
  vector<vector<int>> link(m, vector<int>(3)); 
  for(int a=0; a<m; a++) cin>>link[a][1]>>link[a][2]>>link[a][0]; 
  sort(link.rbegin(), link.rend()); 

  for(int a=0; a<m; a++){
    DSU(link[a][1], link[a][2]); 
    if(graph[link[a][1]]==link[a][2] && graph[link[a][2]]==link[a][1]){
      visit[link[a][1]]=1; 
      visit[link[a][2]]=1; 
    }
    int root, b;
    for(b=1; b<n+1; b++) if(!visit[b]) {root=find(b); break; }
    bool valid=true; 
    for(b=b+1; b<n+1; b++){
      if(!visit[b]){
        int x=find(b); 
        if(x!=root) {valid=false; break;}
        root=x; 
      }
    }
    if(valid){cout<<link[a][0]<<endl; return 0;}
  }

}