#include <bits/stdc++.h>
using namespace std;

int N; 
vector<int> pre; 

// int BSerach(int k, int l){
//     int r=pre.size()-1; 

//     while(true){
//         int middle=(l+r)/2; 
//         if()
//     }
// }

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        cin>>N; 
        
        vector<int> ar(N+1); 
        for(int a=1; a<N+1; a++) cin>>ar[a]; 

        int Q; cin>>Q; 
        for(int i=0; i<Q; i++){
            int x, y; cin>>x>>y; 
            
            vector<int> emp(N); 
            int ans=-1; 
            pre=emp; pre[x]=ar[x];
            for(int a=x+1; a<N+1; a++){
                pre[a]=pre[a-1]&ar[a]; 
                //cout<<pre[a]<<" "; 
                if(pre[a]>=y) ans=a; 
            }
            cout<<ans<<" "; 
        }
        cout<<"\n"; 
    }
}