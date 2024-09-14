#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin>>n; 
    
    vector<int> ar(n); 
    for(int a=0; a<n; a++) cin>>ar[a]; 
    sort(ar.begin(), ar.end()); 

    int end=ar[ar.size()-1]; 
    int ans=0, i=ar.size()-2; 
    while(i>=0){
        if(end>=ar[i]){
            ans+=ar[i]; 
            end-=ar[i]; 
            i--; 
        }
        else{
            ar[i]-=end; 
            ans+=end; 
            end=ar[i]; 
            i--; 
        }
    }
    cout<<ans<<endl; 
}