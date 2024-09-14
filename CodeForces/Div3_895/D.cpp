#include <bits/stdc++.h>
using namespace std; 

int gcd(int a, int b){
    if(a==0) return b; 
    if(b==0) return a; 
    if(a==b) return a; 
    if(a>b) return gcd(a-b, b); 
    return gcd(a, b-a); 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 

    while(T--){
        long long n, x, y; cin>>n>>x>>y; 
        
        long long gcd1=gcd(x, y); 
        unsigned long long int lcm=(x/gcd1)*1ll*y; 

        long long p1, p2; 
        p1=(n/x)-(n/lcm), p2=(n/y)-(n/lcm); 

        long long ans=(n-p1+1+n)*p1/2-(1+p2)*p2/2; 

        cout<<ans<<endl; 
    }
}