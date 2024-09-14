#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    vector<int> H(N); 
    for(int a=0; a<N; a++){
        cin>>H[a]; 
    }

    cout<<'0'<<" "; 
    for(int a=2; a<=N; a++){
        int mn=100001; 
        for(int b=0; b<=N-a; b++){
            int L, R; L=b; R=b+a-1; 
            //int mid=(R-L)/2; 
            int mid=(R+L)/2; 

            int sum=0; 
            //cout<<L<<" "<<R<<endl; 
            if(a%2==0){
                for(int i=1; i+mid<=R; i++){
                    sum+=abs(H[mid+1-i]-H[mid+i]); 
                }
            }
            else{
                for(int i=1; i+mid<=R; i++){
                    sum+=abs(H[mid-i]-H[mid+i]); 
                } 
            }
            mn=min(sum, mn); 
        }
        cout<<mn<<" "; 
    }
    cout<<endl; 
}