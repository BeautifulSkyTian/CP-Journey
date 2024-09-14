#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int T; cin>>T; 
    while(T--){
        int n; cin>>n; 
        string box1, box2; 
        cin>>box1>>box2; 

        int supposed=0, nSupposed=0; 
        for(int a=0; a<n; a++){
            if((box1[a]-48) && !(box2[a]-48)) nSupposed++; 
            else if(!(box1[a]-48) && (box2[a]-48)) supposed++; 
        }

        cout<<max(nSupposed, supposed)<<endl; 
    }
}