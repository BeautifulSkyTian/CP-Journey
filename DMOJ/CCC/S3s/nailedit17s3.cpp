#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 

    vector<int> H(4001, 0), L(4001, 0); 

    for(int a=0, b; a<N; a++) {cin>>b; L[b]++;}

    for(int h=2; h<=4000; h++){
        for(int a=1; a<=h/2; a++){
            int b=h-a;
            if(a==b) H[h]+=L[a]/2; 
            else H[h]+=min(L[a], L[b]); 
        }
    }

    int x=0; 
    int mx=*max_element(H.begin(), H.end()); 
    for(int a=0; a<=4000; a++) if(H[a]==mx) x++; 
    cout<<mx<<" "<<x<<endl; 
}