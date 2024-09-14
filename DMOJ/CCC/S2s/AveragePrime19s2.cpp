#include <bits/stdc++.h>
using namespace std; 

bool composite(int num){
    for(int a=2; a<=sqrt(num); a++){
        if(num%a==0) return 1; 
    }
    return 0; 
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    
    for(int a=0; a<N; a++){
        int x; cin>>x; 
        int alpha=x*2;

        for(int b=2; b<=alpha/2; b++){
            int beta=alpha-b; 

            if(!composite(b) && !composite(beta)){
                cout<<b<<" "<<beta<<endl;
                break; 
            }

        }
    }
}