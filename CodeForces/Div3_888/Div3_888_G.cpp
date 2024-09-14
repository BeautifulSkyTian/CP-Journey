#include <bits/stdc++.h>
using namespace std; 

const int MAXN=2e5; 

vector<int> parent(MAXN+1); 
vector<int> H(MAXN+1); 

int find_set(int v){
    if(v==parent[v]) return v; 
    return parent[v]=find_set(parent[v]); 
}

void union_set(int a, int b){
    a=find_set(a); 
    b=find_set(b); 
    if(a!=b) parent[b]=a; 
}

int main(){
    int T; cin>>T; 

    while(T--){
        int n, m; cin>>n>>m; 
        for(int a=1; a<=n; a++){
            int x; cin>>x; 
            H[a]=x;
            parent[a]=a; 
        }

        for(int a=0; a<m; a++){
            int x, y; cin>>x>>y; 
            union_set(x, y); 
        }

        int l; cin>>l; 
        for(int a=0; a<l; a++){
            int x, y, z; cin>>x>>y>>z; 
            if(find_set(x)==find_set(y)) cout<<"YES"<<endl; 
            else cout<<"NO"<<endl; 
        }
        cout<<endl; 

    }


}