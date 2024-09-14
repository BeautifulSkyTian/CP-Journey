#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    
    for(int a=0; a<N; a++){
        int n, m, k, H; cin>>n>>m>>k>>H; 

        int ans=n; 
        for(int b=0; b<n; b++){
            int x; cin>>x; 
            if(abs(H-x)>(m-1)*k || abs(H-x)%k || H==x || m==1) ans--; 
        }
        cout<<ans<<endl; 

    }
}