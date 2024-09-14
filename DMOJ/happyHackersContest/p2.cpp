#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int n, q; cin>>n>>q; 
    vector<int> ar(n); 
    for(int a=0; a<n; a++) cin>>ar[a]; 

    while(q--){
        int l, r; cin>>l>>r; 
        l--, r--; 

        vector<int> table(10e6+1); 
        bool valid=false, same=true; 
        for(int a=l; a<=r; a++){
            if(ar[a]==0){
                valid=true;
                break; 
            }
            else if(ar[a]<0){
                if(table[abs(ar[a])]==1) {valid=true; break;}
                else table[abs(ar[a])]=-1; 
            }
            else{
                if(table[abs(ar[a])]==-1) {valid=true; break;}
                else table[abs(ar[a])]=1; 
            }
            if(a<=r-1 && ar[a]!=ar[a+1]) same=false; 
        }

        if(valid || same) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
}