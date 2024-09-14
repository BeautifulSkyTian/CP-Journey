#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    vector<int> data(N); 
    vector<int> high, low; 

    for(int a=0; a<N; a++) cin>>data[a]; 
    sort(data.begin(), data.end()); 

    for(int a=0; a<N; a++){
        if(a<(N+1)/2) low.push_back(data[a]); 
        else high.push_back(data[a]); 
    }
    sort(low.begin(), low.end(), greater<int>()); 

    for(int a=0; a<N/2; a++){
        cout<<low[a]<<" "<<high[a]<<" "; 
    }

    if(N%2!=0) cout<<low[low.size()-1]<<endl; 
    else cout<<endl; 
}