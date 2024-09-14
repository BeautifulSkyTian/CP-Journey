#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    vector<int> assign(10000); 

    int N; cin>>N; 

    for(int a=0; a<N; a++){
        int m, n; cin>>m>>n; 

        assign[m]=n; 
    }

    while(true){
        int m, n; cin>>m>>n; 
        int sep=-1; 
        if(m==0 && n==0) break; 

        vector<int> vis(10000); 
        bool same=false; 
        int node=m; 
        while(true){
            if(node==n){
                same=true; 
                break; 
            }
            if(!vis[node]){
                vis[node]=1; 
                node=assign[node]; 
                sep++; 
            }
            else break; 
        }
        if(same) {cout<<"Yes "<<sep<<endl; continue;}

        node=n; 
        while(true){
            if(node==m){
                same=true; 
                break; 
            }
            if(!vis[node]){
                vis[node]=1; 
                node=assign[node]; 
                sep++; 
            }
            else break; 
        }
        if(same) {cout<<"Yes "<<sep<<endl; continue;}
        else {cout<<"No "<<endl; continue;}
    }    
}