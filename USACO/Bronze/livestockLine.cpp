#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ar(8); 
vector<int> vis(8, 0); 
vector<int> ans; 

void dfs(int node){
    for(int i: ar[node]){
        if(!vis[i]){
            ans.push_back(i); 
            vis[i]=1; 
            dfs(i); 
        } 

    }
}

int main()
{
  cin.sync_with_stdio(0); 
  cin.tie(0); 

  freopen("lineup.in", "r", stdin);
  // the following line creates/overwrites the output file
  freopen("lineup.out", "w", stdout);

  map<string, int> cow1; 
  vector<string> cow2{"Bessie", "Buttercup", "Belinda", "Beatrice" , "Bella", "Blue", "Betsy", "Sue"};   
  sort(cow2.begin(), cow2.end()); 
  for(int a=0; a<cow2.size(); a++) cow1[cow2[a]]=a; 
//   for(pair<string, int> i: cow1) cout<<i.first<<" "<<i.second<<endl; 

  string m; getline(cin, m); 
  int n=stoi(m); 
  for(int a=0; a<n; a++){
    vector<int> x; 
    string str; getline(cin, str); 
    for(int a=0; a<str.size(); a++) if(str[a]==' ') {x.push_back(cow1[str.substr(0, a)]); break;}
    for(int a=str.size()-1; a>=0; a--) if(str[a]==' ') {x.push_back(cow1[str.substr(a+1, str.size()-1-a)]); break;}

    ar[x[0]].push_back(x[1]); 
    ar[x[1]].push_back(x[0]); 
  }

//   for(vector<int> i: ar){
//     for(int j: i) cout<<j<<" "; 
//     cout<<endl; 
//   }

  for(int a=0; a<8; a++) sort(ar[a].begin(), ar[a].end()); 

  for(int a=0; a<8; a++) if(!vis[a] && ar[a].size()<2) {vis[a]=1; ans.push_back(a); dfs(a);}
  for(int a=0; a<8; a++) cout<<cow2[ans[a]]<<endl; 
}