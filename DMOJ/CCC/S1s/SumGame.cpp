#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    vector<int>sw(N), se(N); 
    for(int a=0; a<N; a++) cin>>sw[a]; 
    for(int a=0; a<N; a++) cin>>se[a]; 

    int sum1=0, sum2=0; 
    int K1=0, K2=0; 
    for(int a=0; a<N; a++){
        sum1+=sw[a]; sum2+=se[a]; 
        if(sum1==sum2) {K2=a+1; K1=max(K1, K2);}
    }
    cout<<K1<<endl; 
}