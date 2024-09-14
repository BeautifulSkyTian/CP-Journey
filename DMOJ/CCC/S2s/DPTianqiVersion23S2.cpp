#include <bits/stdc++.h>
using namespace std; 

const int MAX=5001, INF=INT_MAX; 
vector<int> ans(MAX); 
vector<int> ar(MAX); 
vector<vector<int>> dp(MAX, vector<int>(MAX)); 

int main(){
    fill(ans.begin(), ans.end(), INF); 
    ans[0]=0; 

    int N; cin>>N; 
    for(int a=0; a<N; a++) cin>>ar[a]; 
    for(int a=0; a<N-1; a++){
        dp[a][a+1]=abs(ar[a]-ar[a+1]); 
        ans[1]=min(ans[1], dp[a][a+1]); 
    }

    for(int a=2; a<N; a++){
        for(int b=0; b<N-a; b++){
            dp[b][b+a]=dp[b+1][b+a-1]+abs(ar[b]-ar[b+a]); 
            ans[a]=min(dp[b][b+a], ans[a]); 
        }
    }

    for(int a=0; a<N; a++) cout<<ans[a]<<' '; 
    cout<<endl; 
}