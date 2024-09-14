#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    int N; cin>>N; 
    vector<vector<int>> tensor(1024, vector<int>(1024)); 

    int m, n; cin>>m>>n; 
    vector<vector<int>> op1(m, vector<int>(n)); 
    for(int a=0; a<m; a++){
        for(int b=0; b<n; b++){
            int x; cin>>x; 
            op1[a][b]=x; 
        }
    }

    for(int a=0; a<N-1; a++){
        int i, j; cin>>i>>j; //2, 2
        m*=i, n*=j; //4, 4

        vector<vector<int>> op2(i, vector<int>(j)); 
        vector<vector<int>> op3(m, vector<int>(n)); 

        for(int b=0; b<i; b++){
            for(int c=0; c<j; c++){
                int x; cin>>x; 
                op2[b][c]=x; 
            }
        }

        int row=0, col=0, op2Row=0; //row and col for op1 iteartion. op2Row for op2 iteartion.
        for(int c=0; c<m; c++){
            if(c%i==0 && c!=0) {row++; op2Row=0; }
            for(int d=0; d<n; d+=j, col++){
                for(int e=0; e<j; e++){
                    tensor[c][d+e]=op2[op2Row][e]*op1[row][col];    
                    op3[c][d+e]=tensor[c][d+e]; 
                }
            }
            col=0; 
            op2Row++; 
        }
        op1=op3; 

    }

    // for(int a=0; a<m; a++){
    //         for(int b=0; b<n; b++) cout<<tensor[a][b]<<" "; 
    //         cout<<endl; 
    //     }
    int mx=INT_MIN, mn=INT_MAX, maxRowSum=INT_MIN, minRowSum=INT_MAX, maxColSum=INT_MIN, minColSum=INT_MAX; 
    for(int a=0; a<m; a++){
        int o=0; 
        for(int b=0; b<n; b++){
            mx=max(mx, tensor[a][b]); 
            mn=min(mn, tensor[a][b]); 
            o+=tensor[a][b]; 
        }
        maxRowSum=max(maxRowSum, o); 
        minRowSum=min(minRowSum, o); 
    }

    for(int a=0; a<n; a++){
        int o=0; 
        for(int b=0; b<m; b++) o+=tensor[b][a];
        maxColSum=max(maxColSum, o); 
        minColSum=min(minColSum, o); 
    }

    cout<<mx<<endl<<mn<<endl<<maxRowSum<<endl<<minRowSum<<endl<<maxColSum<<endl
    <<minColSum<<endl;
}