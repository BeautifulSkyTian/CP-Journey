#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    
    while(T--){
        int n; cin>>n; 
        vector<pair<int, int>> ar(n+1); 
        vector<long long> ans(n+1); 

        long long s1=0, s2=0; 

        for(int a=1; a<=n; a++){
            int x; cin>>x; 
            ar[a]={x, a}; 
            s2+=x;         
        }
        sort(ar.begin()+1, ar.end()); 

        for(int a=1; a<=n; a++){
            s2-=ar[a].first; 
            s1+=ar[a].first; 

            ans[ar[a].second]=n+1ll*ar[a].first*(2*a-n)-s1+s2; // The reason why you do not do 0 indexing for this question is because the iteration variable a is used as the number of 's'. If we were to use 0 indexing, the number of 
        } // 's' is decreased by 1. 

        for(int a=1; a<=n; a++) cout<<ans[a]<<" \n"[a==n]; 
    }
}