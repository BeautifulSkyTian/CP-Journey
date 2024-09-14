#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.sync_with_stdio(0); 
  cin.tie(0); 

  freopen("gymnastics.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("gymnastics.out", "w", stdout);

  int K, N; cin>>K>>N; 
  
  vector<pair<int, int>> ar; 
  for(int a=1; a<=N; a++){
    for(int b=1; b<=N; b++) if(a!=b) ar.push_back({a, b}); 
  }
  vector<int> vis(ar.size()); 

  for(int a=0; a<K; a++){
    vector<int> rank(N+1); 
    for(int b=1; b<=N; b++){
      int x; cin>>x; 
      rank[x]=b; 
    }

    for(int b=0; b<ar.size(); b++){
      if(!vis[b] && rank[ar[b].first]<rank[ar[b].second]) vis[b]=1; 
    }
  }

  int ans=0; 
  for(int a=0; a<ar.size(); a++) if(!vis[a]) ans++; 
  cout<<ans<<endl; 
}