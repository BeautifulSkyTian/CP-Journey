#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1000;
bool vis[MAXN][MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ms(vis,0);

    int N; cin>>N;
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            cin>>vis[y][x];
    
    int rooms=0;
    queue<vector<int>> qu;
    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            if (!vis[a][b]) {
                vis[a][b]=1;
                qu.push({a,b});
                while (SZ(qu)) {
                    vector<int> node=qu.front(); qu.pop();
                    for (int y=node[0]-1; y<=node[0]+1; y++) {
                        for (int x=node[1]-1; x<=node[1]+1; x++) {
                            if (!vis[y][x]) {
                                vis[y][x]=1;
                                qu.push({y,x});
                            }
                        }
                    }
                }
                rooms++;
            }
        }
    }
    cout << rooms << endl;    
}