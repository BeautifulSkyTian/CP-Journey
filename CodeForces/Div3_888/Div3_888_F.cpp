#include <bits/stdc++.h>
using namespace std; 

const int MAXN=2e5; 
vector<int> decimal(MAXN); 
vector<vector<int>> binary(MAXN); 
int n, k; 

void binConvert(int p, int num){
    int x=0; 
    int numero=num; 
    while(true){
        numero=numero/2; 
        if(numero>0) x++; 
        else break; 
    }
    binary[p][k-2-x]=1; 
    if(num>pow(2, x)) binConvert(p, num-pow(2, x)); 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 

    while(T--){
        cin>>n>>k; 

        for(int a=0; a<n; a++){
            binary[a].clear(); 
            binary[a].resize(k-1, 0); 
        }

        for(int a=0; a<n; a++){
            int x; cin>>x; 
            decimal[a]=x; 
            binConvert(a, x); 
            for(int b=0; b<k-1; b++) cout<<binary[a][b]; 
        }

    }

}