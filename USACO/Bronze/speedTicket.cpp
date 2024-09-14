#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("speeding.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("speeding.out", "w", stdout);

    int n, m; cin>>n>>m; 
    vector<vector<int>> road(n, vector<int>(2)), cow(m, vector<int>(2)); 
    cin>>road[0][0]>>road[0][1]; 
    for(int a=1; a<n; a++) {cin>>road[a][0]>>road[a][1]; road[a][0]+=road[a-1][0]; }
    cin>>cow[0][0]>>cow[0][1]; 
    for(int a=1; a<m; a++) {cin>>cow[a][0]>>cow[a][1]; cow[a][0]+=cow[a-1][0]; }

    // cout<<"road"; 
    // for(vector<int> i: road) cout<<i[0]<<" "<<i[1]<<endl; 
    // cout<<"cow"; 
    // for(vector<int> i: cow) cout<<i[0]<<" "<<i[1]<<endl; 

    int ans=0; 
    int b=0;
    for(int a=0; a<m; a++){
        for(; b<n; b++){
            ans=max(ans, (cow[a][1]-road[b][1])); 
            if(cow[a][0]<=road[b][0]){
                if(cow[a][0]==road[b][0]) b++; 
                break; 
            }
        }
    }
    cout<<ans<<endl;
}