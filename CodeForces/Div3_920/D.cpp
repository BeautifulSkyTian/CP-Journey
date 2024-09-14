#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); 
    cin.tie(0); 

	int T; cin>>T; 
	while(T--){
		int n, m; cin>>n>>m; 
		vector<int> ar1(n), ar2(m); 
		for(int a=0; a<n; a++) cin>>ar1[a]; 
		for(int a=0; a<m; a++) cin>>ar2[a]; 

		sort(ar1.begin(), ar1.end()); 
		sort(ar2.rbegin(), ar2.rend()); 
		
		long long ans=0; 
        for(int a=0; a<n; a++){
            ans+=max(abs(ar2[m-(n-a)]-ar1[a]), abs(ar1[a]-ar2[a]));
        }
        cout<<ans<<endl; 
	}
}
