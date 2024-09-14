#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        vector<int> ar(n); 
        for(int a=0; a<n; a++) cin>>ar[a]; 

        bool valid=true; 
        for(int a=0; a<n-1; a++) if(ar[a]!=ar[a+1]) {valid=false; break;}
        if(valid) {cout<<0<<endl; continue; }

        int mx=*max_element(ar.begin(), ar.end()); 
        int ans=0; 
        while(!valid){
            vector<int> new_ar; 
            for(int a=0; a<ar.size()-1; a++){
                if(ar[a]<mx){
                    ar[a+1]+=ar[a]; 
                    mx=max(mx, ar[a+1]); 
                    ar[a]=-1; 
                    ans++; 
                }
            }
            // for(int a: ar) cout<<a<<" "; 
            // cout<<endl; 
            if(ar[ar.size()-1]<mx && ar.size()>1 && ar[ar.size()-1]<ar[ar.size()-2]){
                ar[ar.size()-2]+=ar[ar.size()-1]; 
                mx=max(mx, ar[ar.size()-2]); 
                ar.pop_back();  
                ans++; 
            }
            // for(int a: ar) cout<<a<<" "; 
            // cout<<endl; 

            for(int a=0; a<ar.size(); a++) if(ar[a]!=-1) new_ar.push_back(ar[a]); 
            ar=new_ar; 
            // for(int a: ar) cout<<a<<" "; 
            // cout<<endl; 
            valid=true;
            for(int a=0; a<ar.size()-1; a++) if(ar[a]!=ar[a+1]) {valid=false; break;}
            // cout<<valid;
        }

        cout<<ans<<endl; 
    }
}