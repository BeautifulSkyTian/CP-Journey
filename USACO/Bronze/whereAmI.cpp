#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    freopen("whereami.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("whereami.out", "w", stdout);

    int n; cin>>n; 
    string str; cin>>str; 

    for(int a=1; a<=n; a++){
        bool valid=true; 
        for(int b=0; b<=n-a; b++){
            string sub=str.substr(b, a); 
            int rep=0; 
            for(int c=0; c<=n-a; c++){
                if(sub==str.substr(c, a)) rep++; 
                if(rep>1) {valid=false; break;}
            }   
            if(!valid) break;
        }
        if(valid) {cout<<a<<endl; return 0; }
    }
}