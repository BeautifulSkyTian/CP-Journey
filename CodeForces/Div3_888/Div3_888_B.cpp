#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    for(int a=0; a<N; a++){
        int n; cin>>n; 

        vector<int> in(n); 
        vector<int> odd, even, oddP, evenP; 
        for(int b=0; b<n; b++){
            int x; cin>>x; 
            in[b]=x; 
            if(x%2){
                odd.push_back(x); 
                oddP.push_back(b); 
            }
            else{
                even.push_back(x); 
                evenP.push_back(b); 
            }
        }

        sort(odd.begin(), odd.end()); 
        sort(even.begin(), even.end()); 
        sort(in.begin(), in.end()); 

        vector<int> sorted(n); 
        for(int b=0; b<odd.size(); b++) sorted[oddP[b]]=odd[b]; 
        for(int b=0; b<even.size(); b++) sorted[evenP[b]]=even[b]; 

        if(in==sorted) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
}