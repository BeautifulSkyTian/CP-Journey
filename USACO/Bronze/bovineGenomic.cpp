#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("cownomics.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("cownomics.out", "w", stdout);

    int m, n; cin>>m>>n; 
    vector<string> good, bad; 

    for(int a=0; a<m; a++){
        string str; cin>>str; 
        good.push_back(str); 
    }
    for(int a=0; a<m; a++){
        string str; cin>>str; 
        bad.push_back(str); 
    }

    int ans=0; 
    for(int a=0; a<n; a++){
        int A=0, G=0; 
        bool valid=true; 
        for(int b=0; b<m; b++){
            if(good[b][a]=='T' || good[b][a]=='C') break; 
            if(good[b][a]=='A') A=1; 
            if(good[b][a]=='G') G=1; 
        }
        for(int b=0; b<m; b++){
            if((bad[b][a]=='A' && A) || (bad[b][a]=='G' && G)) {valid=false; break;}
        }
        if(valid && (A || G)) ans++; 
    }

    cout<<ans<<endl; 
    
}