#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    int y, m, d; 

    for(int a=0; a<N; a++){
        cin>>y>>m>>d; 
        if(2007-y==18){
            if(m>2) cout<<"No"<<endl;
            else if(m==2){
                if(d<=27) cout<<"Yes"<<endl; 
                else cout<<"No"<<endl; 
            }
            else if(m==1) cout<<"Yes"<<endl; 
        }
        else if(2007-y>18)cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 
    }
}