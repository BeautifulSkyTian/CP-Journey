#include <bits/stdc++.h>
using namespace std; 

int main(){
    int N; cin>>N; 

    vector<vector<int>> triangles(4, vector<int>(N+2,0)); 


    for(int a=1; a<=2; a++){
        for(int b=1; b<=N; b++){
            cin>>triangles[a][b]; 
        }
    }
    int m=0; 

    for(int a=1; a<N+1; a++){
        if(triangles[1][a]){
            if(!triangles[1][a-1] && !triangles[1][a+1]) m+=3; 
            else if(!triangles[1][a-1] || !triangles[1][a+1]) m+=2; 
            else m++; 
        }
    }
    
    for(int a=1; a<N+1; a++){
        if(triangles[2][a]){
            if(!triangles[2][a-1] && !triangles[2][a+1]) m+=3; 
            else if(!triangles[2][a-1] || !triangles[2][a+1]) m+=2; 
            else m++; 
            if(a%2 && triangles[1][a]) m-=2; 
        }
    }
    
    cout<<m<<endl; 
}