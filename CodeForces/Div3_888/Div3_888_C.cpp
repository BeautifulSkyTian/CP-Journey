#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    for(int a=0; a<N; a++){
        int n, k; cin>>n>>k; 
        
        vector<int> tiles(n); 
        for(int b=0; b<n; b++){
            int x; cin>>x; 
            tiles[b]=x; 
        }

        int start=tiles[0], end=tiles[n-1]; 

        if(start==end){
            int ans=0; 
            for(int b=0; b<n; b++){
                if(tiles[b]==start) ans++; 
            }
            if(ans>=k) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
        else if(start!=end){
            int ansStart=0, ansEnd=0; 
            int b=0, c=n-1; 
            for(; b<n; b++){
                if(tiles[b]==start) ansStart++; 
                if(ansStart==k) break; 
            }
            for(; c>b; c--){
                if(tiles[c]==end) ansEnd++; 
                if(ansEnd==k) break; 
            }

            if(ansStart==k && ansEnd==k) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
        else cout<<"NO"<<endl; 
    }
}