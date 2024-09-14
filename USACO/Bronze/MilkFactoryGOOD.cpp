#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> graph; 
vector<int> vis;
 
void dfs(int node){
	for(int i: graph[node]){
		vis[i]++; 
		dfs(i); 
	}
}

int main()
{
	cin.sync_with_stdio(0); 
	cin.tie(0); 

	freopen("factory.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("factory.out", "w", stdout);

	int n; cin>>n; 
	graph.resize(n+1); 
	vis.resize(n+1, 0); 

	for(int a=0; a<n-1; a++){
		int x, y; cin>>x>>y; 
		graph[x].push_back(y); 
	}

	for(int a=1; a<=n; a++){
		dfs(a); 
	}

	for(int a=1; a<=n; a++){
		if(vis[a]==(n-1)){
			cout<<a<<endl; 
			return 0; 
		}
	}
	cout<<-1<<endl; 

}