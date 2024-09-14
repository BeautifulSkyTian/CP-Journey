#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int N; cin>>N; 
        vector<int> ar(N); ar[0]=2; ar[1]=3; 

        for(int a=0; a<N-2; a++){
            ar[a+2]=ar[a+1]+1; 
            while(!(3*ar[a+2]%(ar[a]+ar[a+1]))) ar[a+2]++; 
        }
        for(int i: ar) cout<<i<<" "; 
        cout<<"\n"; 
    }
}
