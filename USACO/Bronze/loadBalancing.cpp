#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 
    /*  This solution is very smart. Fist, DONT EVEN bother checking every single coordinate because you would have to check 1000000^2 dots. Instead
        this solution just gets every single possible fences, so you can check for every single section. There are only 100 cows, so there won't even be
        that many fences. 
    */

    freopen("balancing.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("balancing.out", "w", stdout);

    int n, b; cin>>n>>b; 
    vector<int> cowX(n), cowY(n); 
    set<int> fenceX, fenceY; 
    for(int a=0; a<n; a++){
        cin>>cowX[a]>>cowY[a]; 
        fenceX.insert(cowX[a]+1); 
        fenceY.insert(cowY[a]+1); 
    }

    int ans=n; 
    for(int a: fenceX){
        for(int b: fenceY){
            int topLeft=0, topRight=0, bottomLeft=0, bottomRight=0; 

            for(int c=0; c<n; c++){
                if(cowX[c]<a && cowY[c]>b) topLeft++; 
                else if(cowX[c]>a && cowY[c]>b) topRight++; 
                else if(cowX[c]<a && cowY[c]<b) bottomLeft++; 
                else if(cowX[c]>a && cowY[c]<b) bottomRight++; 
            }

            ans=min(ans, max({topLeft, topRight, bottomLeft, bottomRight})); 
        }
    }

    cout<<ans<<endl; 
}
    