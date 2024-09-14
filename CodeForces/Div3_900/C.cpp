#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        long long n, k, x; 
        cin>>n>>k>>x; 
        if(((n-k+1+n)*k/2<x) || ((1+k)*k/2>x)) cout<<"NO"<<endl; 
        else cout<<"YES"<<endl; 
    }
}