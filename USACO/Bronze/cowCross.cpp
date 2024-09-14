#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("circlecross.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("circlecross.out", "w", stdout);


    vector<vector<int>> ar('Z'+1); 
    for(int a=0; a<52; a++){
        char x; cin>>x; 
        ar[x].push_back(a); 
    }
    
    int ans=0; 
    for(int a=0; a<25; a++){
        for(int b=a+1; b<26; b++){
            int first=a+65, second=b+65; 
            if((ar[first][0]>ar[second][0] && ar[first][0]<ar[second][1] && ar[first][1]>ar[second][1]) || (ar[second][0]>ar[first][0] && ar[second][0]<ar[first][1] && ar[second][1]>ar[first][1])){
                ans++; 
            }
        }
    }
    cout<<ans<<endl; 
}