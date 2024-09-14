#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        vector<pair<int, int>> ar(4); 
        for(int a=0; a<4; a++) cin>>ar[a].first>>ar[a].second; 

        sort(ar.begin(), ar.end()); 
        int side=abs(ar[0].second-ar[1].second); 
        cout<<side*side<<endl; 
    }
}