#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 
 
    long long T; cin>>T; 
    while(T--){
        long long n, f, a, b; cin>>n>>f>>a>>b; 
        vector<long long> ar(n+1); 
        for(long long i=1; i<=n; i++) cin>>ar[i]; 
        if(b<=a){
            if(b*(ar.size()-1)>=f) cout<<"NO"<<endl; 
            else cout<<"YES"<<endl; 
        }
        else{
            for(long long i=1; i<n+1; i++){
                if((ar[i]-ar[i-1])*a>b) f-=b; 
                else f-=(ar[i]-ar[i-1])*a; 
                // cout<<f<<" "; 
            }
            if(f>0) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
    }
}