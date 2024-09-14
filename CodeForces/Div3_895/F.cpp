#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 
 
    int T; cin>>T; 
    while(T--){
        int N; cin>>N; 
        
        vector<int> ar(N), c(N), son(N); 
        for(int a=0; a<N; a++){
            int x; cin>>x; x-=1; 
            ar[a]=x; 
            son[x]+=1; 
        }
        for(int a=0; a<N; a++) cin>>c[a]; 
 
        vector<int> q; 
        for(int a=0; a<N; a++) if(son[a]==0) q.push_back(a); 
        vector<int> ans, visited(N); 
        while(q.size()>0){
            int v=q[q.size()-1]; //Stack 
            ans.push_back(v); 
            q.pop_back(); 
            visited[v]=1; 
            son[ar[v]]-=1; 
            if(son[ar[v]]==0) q.push_back(ar[v]); 
        }
        for(int a=0; a<N; a++){
            if(!visited[a]){
                int v2=ar[a]; 
                vector<int> cycle{a}; 
                while(v2!=a){
                    cycle.push_back(v2); 
                    v2=ar[v2]; 
                }
                int minc=1000000000; 
                for(int i: cycle){
                    visited[i]=1; 
                    minc=min(minc, c[i]); 
                }
                for(int i=0; i<cycle.size(); i++){
                    if(c[cycle[i]]==minc){
                        for(int b=i+1; b<cycle.size(); b++) ans.push_back(cycle[b]); 
                        for(int b=0; b<i+1; b++) ans.push_back(cycle[b]); 
                        break; 
                    }
                }
            }
        }
        for(int a=0; a<N; a++) cout<<ans[a]+1<<" "; 
        cout<<"\n"; 
    }
}