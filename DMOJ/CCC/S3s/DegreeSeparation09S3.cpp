#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 

    vector<vector<int>> graph(50, vector<int>(50, 0)); 
    
    for(int a=1; a<=4; a++){
        graph[a][6]=1; 
        graph[6][a]=1; 
    }

    for(int a=3; a<18; a++){
        graph[a][a+1]=1; 
        graph[a+1][a]=1; 
    } // Get rid of 14-15, 15-16. Get 3-5, 3-15, 15-13, 16-18, 9-12

    graph[3][5]=1, graph[5][3]=1, graph[3][15]=1, graph[15][3]=1, graph[13][15]=1, graph[15][13]=1, graph[14][15]=0, graph[15][14]=0, graph[15][16]=0, graph[16][15]=0, graph[16][18]=1, graph[18][16]=1, graph[9][12]=1, graph[12][9]=1; 


    while(true){
        char chr; cin>>chr; 
        if(chr=='q') break; 
        else if(chr=='i'){
            int x, y; cin>>x>>y; 
            graph[x][y]=1; 
            graph[y][x]=1; 
        }
        else if(chr=='d'){
            int x, y; cin>>x>>y; 
            graph[x][y]=0; 
            graph[y][x]=0; 
        }
        else if(chr=='n'){
            int x; cin>>x; 
            int num=0; 
            for(int a=1; a<50; a++){
                if(graph[x][a]) num++; 
            }
            cout<<num<<endl; 
        }
        else{
            vector<int> vis(50); 
            vector<int> vis2(50); 
            queue<pair<int, int>> dir; 
            int x, y; 
            if(chr=='f') cin>>x; 
            else cin>>x>>y; 
            
            dir.push({x, 0}); 
            vis[x]=1; 
            int num=0; 

            while(dir.size()>0){
                pair<int, int> node=dir.front(); 
                dir.pop(); 

                if(node.second==1) vis2=vis; 
                if(node.second==2 && chr=='f') {cout<<num<<endl; break;}
                else if(chr=='s' && node.first==y) {cout<<node.second<<endl; break;}

                for(int a=1; a<50; a++){
                    if(graph[node.first][a] && !vis[a]){
                        dir.push({a, node.second+1}); 
                        vis[a]=1; 
                        if(node.second%2 && !vis2[a]) num++;
                    } 
                }
            }

            if(!vis[y] && chr=='s') cout<<"Not connected"<<endl; 
        }
    }
}