#include <bits/stdc++.h>
using namespace std; 

int MAXN=2001; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N, M, R, C; 
    cin>>N>>M>>R>>C; 

    vector<vector<char>> row(MAXN, vector<char>(MAXN, 'a')); 

    if((R==N && C%2!=0 && M%2==0) || (C==M && R%2!=0 && N%2==0)) {cout<<"IMPOSSIBLE"<<endl; return 0;}
    else if(R==N && C!=M){
        int y=C/2; 
        char x=98; 
        for(int a=0; a<N; a++){
            if(x==122) x=97; 
            fill_n(row[a].begin()+y, M-y*2, x); 
            x++; 
        }
        if(C%2!=0){
            for(int a=0; a<N; a++) row[a][M/2]='a'; 
        }
    }
    else if(C==M && R!=N){
        int y=R/2; 
        for(int a=y; a<N-y; a++){
            char x=98; 
            for(int b=0; b<M; b++){
                if(x==122) x=97; 
                row[a][b]=x; 
                x++; 
            }
        }
        if(R%2!=0) fill(row[N/2].begin(), row[N/2].end(), 'a'); 
    }
    else if(R==0 && C==0){
        char i=97, ii=97; 
        for(int a=0; a<N; a++){
            if(ii==122) ii=97; 
            ii++; 
            i=ii;
            for(int b=0; b<M; b++){
                if(i==122) i=97; 
                i++; 
                row[a][b]=i; 
            }
        }
    }
    else{
        char i=97, ii=97; 
        for(int a=R; a<N; a++){
            if(ii==122) ii=97; 
            ii++; 
            i=ii;
            for(int b=C; b<M; b++){
                if(i==122) i=97; 
                i++; 
                row[a][b]=i; 
            }
        }
    }

    for(int a=0; a<N; a++){
            for(int b=0; b<M; b++) cout<<row[a][b]; 
            cout<<endl; 
    }
}