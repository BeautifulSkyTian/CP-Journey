#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("blocks.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("blocks.out", "w", stdout);

    vector<int> ans('z'+1); 
    int n; cin>>n; 
    for(int a=0; a<n; a++){
        vector<vector<int>> character('z'+1, vector<int>(2)); 
        string x, y; cin>>x>>y; 
        for(int b=0; b<x.size(); b++) character[x[b]][0]++; 
        for(int b=0; b<y.size(); b++) character[y[b]][1]++; 
        for(int b='a'; b<='z'; b++){
            ans[b]+=max(character[b][0], character[b][1]); 
        }
    }

    for(int a='a'; a<='z'; a++) cout<<ans[a]<<endl; 

}