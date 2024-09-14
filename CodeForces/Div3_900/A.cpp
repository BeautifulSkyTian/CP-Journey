#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    
    while(T--){
        int N, k; cin>>N>>k; 
        vector<int> ar(N), K; 
        for(int a=0; a<N; a++){
            cin>>ar[a]; 
            if(ar[a]==k) K.push_back(a);
        }
        if(K.size()<1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl; 
        }
    }
}