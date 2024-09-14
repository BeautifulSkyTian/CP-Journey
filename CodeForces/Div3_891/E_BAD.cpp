#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 

    while(T--){
        int n; cin>>n; 
        vector<pair<int, int>> ar(n+1); 

        for(int a=1; a<=n; a++){
            int x; cin>>x; 
            ar[a]={x, a}; 
        }
        sort(ar.begin()+1, ar.end()); 

        vector<int> sortPos(n+1); 
        for(int a=1; a<=n; a++) sortPos[ar[a].second]=a; 

        for(int a=1; a<=n; a++){
            long long ans=n+1ll*ar[sortPos[a]].first*(2*sortPos[a]-n); 
            for(int b=1; b<=n; b++){
                if(b<=sortPos[a]) ans-=ar[b].first; 
                else ans+=ar[b].first; 
            }
            cout<<ans<<" ";
        }

        cout<<"\n"; 
        

    }
}