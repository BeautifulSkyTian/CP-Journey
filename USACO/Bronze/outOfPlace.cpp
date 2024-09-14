#include <bits/stdc++.h>
using namespace std; 

int main(){
    // freopen("outofplace.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("outofplace.out", "w", stdout);

    int n; cin>>n; 
    vector<int> ar(n); 
    for(int a=0; a<n; a++) cin>>ar[a]; 

    vector<int> sorted(ar); 
    sort(sorted.begin(), sorted.end()); 

    int ans=0; 
    for(int a=0; a<n; a++){
        if(ar[a]!=sorted[a]) ans++; 
    }
    cout<<ans-1<<endl; 
}