#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int x, y; cin>>x>>y; 
        
        if(x==y){
            bool valid=false;  
            for(int a=2; a*a<=x; a++){
                if(x%a==0){
                    cout<<a<<" "<<x-a<<endl; 
                    valid=true; 
                    break;
                }
            }
            if(!valid) cout<<-1<<endl; 
        }
        else{
            if(y<=3) cout<<-1<<endl; 
            else {
                for(int a=x; a<=y; a++){
                    if(a%2==0 && a!=2) {cout<<2<<" "<<a-2<<endl; break;}
                }
            }
        }
    }
}