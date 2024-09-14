#include <bits/stdc++.h>
using namespace std; 

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);         
    
    int N, M; cin>>N>>M; 

    vector<vector<int>> graph(N+1); 
    vector<int> trace(N+1, 0); 
    vector<int> friendship(N+1, 0); 

    for(int a=0; a<M; a++){
        int x, y; cin>>x>>y; 
        graph[x].push_back(y); 
        graph[y].push_back(x); 
    }

    queue<pair<int, int>> dir; 
    int node; 
    for(int a=1; a<=N; a++){
        if(!trace[a]) dir.push({a, 1}); //Instead of two while loops to switch to different islands, we can just use a for loop.

        while(dir.size()>0){
            node=dir.front().first; 
            int group=dir.front().second, ngroup=1; 
            dir.pop(); 
            //cout<<"Node: "<<node<<endl;

            if(group==1) ngroup=2; //If the group number of the node is 1, then its child should be different. 

            if(friendship[node]==group) continue;  //This makes it so if two nodes has the same child, this if eliminates repeats. 
            else if(friendship[node]!=0){ //The default group number of a node should be 0 because it is the first time the node is
                cout<<"IMPOSSIBLE"<<endl; //viewed. If the group number were to be the same as when it was pushed, then its ok.
                return 0; //But when it is not zero and does not equal to the group number when the node is pushed, this means 
            }//two people who are friends have been put to the same group. 
            else friendship[node]=group; //This grants the group number to a node when this is the first time a node is viewed. 

            trace[node]=1; 
            for(int a: graph[node]){
                if(!trace[a]) dir.push({a, ngroup});
            }
        }
    }

    for(int a=1; a<=N; a++) cout<<friendship[a]<<" ";
    cout<<endl;
}