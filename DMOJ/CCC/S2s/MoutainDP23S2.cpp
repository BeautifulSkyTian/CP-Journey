#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=5001, INF=INT_MAX;
int dp[MAXN][MAXN], ar[MAXN], ans[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ms(dp,0);
    ms(ar,0);
    fill(ans,ans+MAXN,INF);
    ans[0]=0;

    int N; cin>>N;
    for (int i=0; i<N; i++) cin>>ar[i];
    for (int i=0; i<N-1; i++) dp[i][i+1]=abs(ar[i]-ar[i+1]), ans[1]=min(ans[1], dp[i][i+1]);
    for (int i=2; i<N; i++) {
        for (int a=0; a<N-i; a++) {
            dp[a][a+i]=dp[a+1][a+i-1]+abs(ar[a]-ar[a+i]), ans[i]=min(ans[i],dp[a][a+i]);
        }
    }
    for (int i=0; i<N; i++) cout << ans[i] << ' ';
    cout << endl;
}