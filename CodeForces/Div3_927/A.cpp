#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        string str; cin>>str; 
        
        int ans=0;  
        for(int a=0; a<n;){
            if(str[a]=='@') ans++; 
            
            if(a+1<n && str[a+1]=='*'){
                if(a+2<n && str[a+2]=='*') break; 
                else a+=2; 
            }
            else a++; 
        }
        cout<<ans<<endl; 
    }
}