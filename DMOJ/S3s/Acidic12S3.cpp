#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 

    vector<int> reading(1001); 
    for(int a=0; a<N; a++){
        int x; cin>>x; 
        reading[x]++; 
    }

    int mx=*max_element(reading.begin(), reading.end()); 
    
    vector<int> firLarge; 
    for(int a=1; a<reading.size(); a++){
        if(reading[a]==mx){
            firLarge.push_back(a); 
            reading[a]=0; 
        }
    }

    if(firLarge.size()>1){
        cout<<abs(firLarge[0]-firLarge[firLarge.size()-1])<<endl; 
    }
    else{
        int secMx=*max_element(reading.begin(), reading.end()); 

        vector<int> secLarge; 
        for(int a=1; a<reading.size(); a++){
            if(reading[a]==secMx){
                secLarge.push_back(a); 
            }
        }
        cout<<max(abs(firLarge[firLarge.size()-1]-secLarge[0]), abs(firLarge[firLarge.size()-1]-secLarge[secLarge.size()-1]))<<endl; 
    }
}