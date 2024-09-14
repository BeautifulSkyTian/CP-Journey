#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    while(true){
        int r; cin>>r; 
        if(r==0) break; 
        int ans=0; 
        for(int y=0; y<=r; y++){
            int x=sqrt(r*r-y*y); 
            ans+=x; 
        }
        cout<<ans*4+1<<endl; 
    }
}